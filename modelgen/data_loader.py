"""
Created on Tue Oct 23 14:54:17 2018
Load data
@author: vayer
"""
from graph import Graph
import networkx as nx
from utils import read_files,per_section,indices_to_one_hot
from collections import defaultdict
import numpy as np

class NotImplementedError(Exception):
    pass

def load_local_data(data_path, one_hot=False,attributes=True,use_node_deg=False):
    # cfg data
    #path=data_path+'/CFG/'
    if attributes:
        dataset=build_CFG_dataset(data_path,type_attr='real')
    else:
        dataset=build_CFG_dataset(data_path)
    
    return dataset

#%%
def generate_binary_uniform_tree(maxdepth,coupling='cross',a=0,b=5,c=5,d=10):#il faut que nlowLeaves soit une puissance de 2
    graph=Graph()
    #randint=np.random.randint(2,high=maxdepth)
    randint=maxdepth
    nlowLeaves=2**randint
    groupe=('A',a,b)
    graph.create_classes_uniform_leaves(nlowLeaves,groupe)
    groupe=('B',c,d)
    graph.create_classes_uniform_leaves(nlowLeaves,groupe)
    noeud_0=graph.find_leaf('A')
    noeud_1=graph.find_leaf('B')
    if coupling=='cross':            
        k=0
        for noeud in noeud_0:
            graph.binary_link(noeud,noeud_1[k])
            k=k+1
    else :
        graph.iterative_binary_link(noeud_0,maxIter=1)
        graph.iterative_binary_link(noeud_1,maxIter=1)
    otherNode=list(set(graph.nodes()).difference(set(noeud_1).union(set(noeud_0))))

    graph.iterative_binary_link(otherNode)
    graph.nx_graph=nx.relabel_nodes(graph.nx_graph,{max(graph.nodes(), key=len):1}) #renomer la racine
    graph.construct_tree()

    return graph

def build_binary_uniform_dataset(nTree1,nTree2,maxdepth,a=0,b=5,c=5,d=10):
    data=[]
    for i in range(nTree1):
        data.append((generate_binary_uniform_tree(maxdepth,coupling='cross',a=a,b=b,c=c,d=d),0))
    for i in range(nTree2):
        data.append((generate_binary_uniform_tree(maxdepth,coupling='nocross',a=a,b=b,c=c,d=d),1))

    return data

def build_one_tree_dataset_from_xml(path,classe,max_depth):
    onlyfiles = read_files(path)
    data=[]
    for f in onlyfiles :
        G=Graph()
        G.build_Xml_tree(path+'/'+f,max_depth)
        data.append((G,classe)) 

    return data

def node_labels_dic(path,name):
    node_dic=dict()
    with open(path+name) as f:
        sections = list(per_section(f))
        k=1
        for elt in sections[0]:
            node_dic[k]=int(elt)
            k=k+1
    return node_dic

def node_attr_dic(path,name):
    node_dic=dict()
    with open(path+name) as f:
        sections = list(per_section(f))
        k=1
        for elt in sections[0]:
            node_dic[k]=[float(x) for x in elt.split(',')]
            k=k+1
    return node_dic

def graph_id(path, name):
	ids = []
	with open(path+name) as f:
		for line in f:
			ids.append(line)
	
	return ids

def graph_label_list(path,name):
    graphs=[]
    with open(path+name) as f:
        sections = list(per_section(f))
        k=1
        for elt in sections[0]:
            graphs.append((k,int(elt)))
            k=k+1
    return graphs
    
def graph_indicator(path,name):
    data_dict = defaultdict(list)
    with open(path+name) as f:
        sections = list(per_section(f))
        k=1
        for elt in sections[0]:
            data_dict[int(elt)].append(k)
            k=k+1
    return data_dict

def compute_adjency(path,name):
    adjency= defaultdict(list)
    with open(path+name) as f:
        sections = list(per_section(f))
        for elt in sections[0]:
            adjency[int(elt.split(',')[0])].append(int(elt.split(',')[1]))
    return adjency


def all_connected(X):
    a=[]
    for graph in X:
        a.append(nx.is_connected(graph.nx_graph))
    return np.all(a)


# cfg
def build_CFG_dataset(path,type_attr='label'):
    graphs=graph_label_list(path,'CFG_graph_labels.txt')
    ids=graph_id(path, 'CFG_graph_id.txt')
    if type_attr=='label':
        node_dic=node_labels_dic(path,'CFG_node_labels.txt')
    if type_attr=='real':
        node_dic=node_attr_dic(path,'CFG_node_attributes.txt')
    adjency=compute_adjency(path,'CFG_A.txt')
    data_dict=graph_indicator(path,'CFG_graph_indicator.txt')
    data=[]
    for i in graphs:
        g=Graph()
        # use graph id instead of No. i[0]
        g.name=ids[i[0]-1]
        for node in data_dict[i[0]]:
            g.add_vertex(node)
            g.add_one_attribute(node,node_dic[node])
            for node2 in adjency[node]:
                g.add_edge((node,node2))
        data.append((g,i[1]))
    # return [(graph, label), ...]
    return data
