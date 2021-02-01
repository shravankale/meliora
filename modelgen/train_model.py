from data_loader import load_local_data
import argparse
import networkx as nx
from pscn import PSCN
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
import numpy as np

'''
Driver for model training 

usage: $python3 train_model.py [path input data]


@Kewen Meng

'''
def load_labels(path):
    '''
    Load class labels from config file
    '''        
    label_list = []
    with open(path) as f:
        for line in f:
            if line is not "":
                label_list.append(line.rstrip())

    return label_list


if __name__ == "__main__":

    
    parser = argparse.ArgumentParser(description='Driver for training model')
    parser.add_argument('input_data', help='Path for the data to predict')
    parser.add_argument('-l', '--labels', dest='label_path', 
                            help='Path to load class labels')
    parser.add_argument('-o', '--out', dest='model_path',
                            help='Path to save trained model')

    args = parser.parse_args()
    model_path = args.model_path

    if model_path is None:
        # default path to load model
        model_path = 'cfg_model.h5'
     
    label_path = args.label_path
    if label_path is None:
        label_path = 'labels_train.txt'

    labels = load_labels(label_path)
    print (labels)
    # read dataset
    cfg_dataset=load_local_data(args.input_data)
    X,y=zip(*cfg_dataset)
    print ('Total graphs: ', len(X))
    pscn=PSCN(w=25,k=10,epochs=50,gpu=True,multiclass=len(labels),batch_size=32,verbose=2,attr_dim=11,dummy_value=np.repeat(0,11), model_path=model_path)
    #X_train, X_test, y_train, y_test=train_test_split(X,y,test_size=0.3, random_state=42)
    pscn.fit(X,y)
    pscn.save(model_path)
