import csv
import sys
from collections import defaultdict
from collections import Counter

'''
Python3 script for analyzing the prediction report

usage: $python3 predAnalyzer.py [csv path]


@Kewen Meng

'''

def get_label(graph_id):
    #return graph_id[0: graph_id.find('_')-1]
    # e.g mvt@1
    return graph_id[0: graph_id.find('_')-1] + graph_id[-3:-1]

def analyzer(csv_path):
    # key: label, value: {label: occurence}
    # e.g. {mm: {mm:20, adi:10, stencil3d:5, ...}, ...} 
    class_dict = defaultdict(lambda: defaultdict(int))
    counter_dict = defaultdict(int)
    # note the csv does not include expected class
    # it parses from the graph id
    # e.g mm2___orio_perftest20.c.30 -> mm
    with open(csv_path, newline='') as f:
        reader = csv.DictReader(f, delimiter=' ')
        for row in reader:
            expected_label = get_label(row['file_id'])
            counter_dict[expected_label] += 1
            # get copy of row without file_id
            copy_row = {k:float(v) for k, v in row.items() if k != 'file_id'}   
            # get pair with max possibility
            pred_label, pct = max(copy_row.items(), key=lambda kv: kv[1])
            class_dict[expected_label][pred_label] += 1
            # show prediction for each test case
            print ('{0} ---> {1}, {2:.2f}'.format(row['file_id'], pred_label, pct))
    
    # print result
    for k, v in counter_dict.items():
        print('{0} has {1} tests.'.format(k, v))
        # sort 
        sorted_dict = sorted(class_dict[k].items(), key=lambda kv: kv[1], reverse=True)
        for l, o in sorted_dict:
            print(' {0} {1:4.2f}% '.format(l, o/v*100), end='')
        print()
        print()
            
             


if __name__ == "__main__":
    
    if len(sys.argv) < 2:
        sys.exit("ERROR, Not enough arguments.")

    csv_path = sys.argv[1]
    analyzer(csv_path)

