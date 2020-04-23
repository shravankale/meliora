from data_loader import load_local_data
import networkx as nx
import argparse
from pscn import PSCN
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
import numpy as np
from prettytable import PrettyTable
import csv
from collections import defaultdict
from collections import Counter

def load_labels(path):
    '''
    Load class labels from config file
    '''        
    label_list = []
    with open(path) as f:
        for line in f:
            label_list.append(line.rstrip())

    return label_list

def write_csv(path, pred, labels, input_graph):
    '''
    Write prediction result to csv
    '''
    fields = ['file_id'] + labels
    with open(path, 'w', newline='') as csvfile:
        writer = csv.DictWriter(csvfile, delimiter=' ', fieldnames=fields)
        writer.writeheader()
        
        for i in range(len(pred)):
            row_value = dict(zip(labels, pred[i]))
            # add file id
            row_value['file_id'] = input_graph[i].name
            writer.writerow(row_value)
    
def gen_stats(pred, expected, train_labels, input_graph, validate_labels):
    '''
    Generate statistics for the results
    '''
    test_counts = defaultdict(int) 
    incorrect_test = defaultdict(list)
    # tests whose labels not in train
    non_train_counts= defaultdict(int)
    # for such tests, it stores as [[graph_id, top1 pred, top2 pred, top3 pred], ...]
    non_train_test = defaultdict(list)
    for i in range(len(pred)):
        # label_name = validate_labels[expected[i]-1]
        expected_label = validate_labels[expected[i]-1]
        if expected_label not in train_labels:
            # this class label is not in training
            non_train_counts[expected_label] += 1
            nt_result = list(zip(preds[i], train_labels))
            nt_result.sort(key=lambda tup: tup[0], reverse=True)
            non_train_test[expected_label].append([input_graph[i].name, nt_result[0][1], nt_result[1][1], nt_result[2][1]])            
        else:
            # expected_label = train_labels[expected[i]-1]
            test_counts[expected_label] += 1
            result = list(zip(preds[i],train_labels))
            result.sort(key=lambda tup: tup[0], reverse=True)
            if result[0][1] != expected_label:
                incorrect_test[expected_label].append((input_graph[i].name, result[0][1]))
         
    with open('stats.out', 'w') as out:
        '''
        for k, v in non_train_counts.items():
           top_pred = Counter(l[1] for l in non_train_test[k]).most_common(3)
           out.write('{0} has {1} tests. {2:4.2f}% predicts as {3}, {4:4.2f}% as {5}, {6:4.2f}% as {7}\n'.format(k, v, top_pred[0][1]/v*100, top_pred[0][0], top_pred[1][1]/v*100, top_pred[1][0], top_pred[2][1]/v*100, top_pred[2][0]))
        print("-----------------------\n")
        '''

        for k, v in test_counts.items():
            incorrect_size = len(incorrect_test[k])
            if incorrect_size > 0:
                top_pred = Counter(l[1] for l in incorrect_test[k]).most_common(1)
                out.write('{0} has {1} tests, {2} are incorrect classified. {3:4.2f}% predicts as {4}. Details listed as follows:\n'.format(k, v, incorrect_size, top_pred[0][1]/incorrect_size*100, top_pred[0][0]))
                for tup in incorrect_test[k]:
                    out.write(' {0}  --->  {1}\n'.format(tup[0], tup[1]))
    

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='Main for prediction results')
    parser.add_argument('input_data', help='Path for the data to predict')
    parser.add_argument('-l', '--labels', dest='train_label_path', 
                            help='Path to load train labels')
    # validate labels are those labels may not be in the training set
    # use it for comparison
    parser.add_argument('-v', '--validate', dest='validate_label_path', 
                            help='Path to load validate labels')
    parser.add_argument('-m', '--model', dest='model_path',
                            help='Path to load model')
    parser.add_argument('-o', '--output', dest='out_file',
                            help='path to save output csv file')
    args = parser.parse_args()
    model_path = args.model_path
    if model_path is None:
        # default path to load model
        model_path = 'cfg_model.h5'
     
    train_label_path = args.train_label_path
    if train_label_path is None:
        train_label_path = 'labels_train.txt'
    
    validate_label_path = args.validate_label_path
    if validate_label_path is None:
        # default value is to use the training label set
        validate_label_path = 'labels_train.txt'

    output_path = args.out_file
    if output_path is None:
        output_path = 'pred_results.csv'

    cfg_dataset=load_local_data(args.input_data)
    X,y=zip(*cfg_dataset)
    print ('Total graphs: ', len(X))
    train_labels = load_labels(train_label_path) 
    # train labels may be a subset of validate labels
    validate_labels = load_labels(validate_label_path) 

    pscn = PSCN(w=25, k=10, epochs=20, multiclass=len(train_labels), batch_size=32, verbose=2, attr_dim=10, dummy_value=np.repeat(0,10), has_model=True, model_path=model_path)
    preds = pscn.predict(X)
    write_csv(output_path, preds, train_labels, X)
    gen_stats(preds, y, train_labels, X, validate_labels)
