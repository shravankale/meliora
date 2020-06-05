# Meliora framework
Meliora is a code analysis infrastructure for machine learning-based performance model generatio of arbitrary codes based on static analysis of intermediate language representations.

## Requirements
LLVM9, CMake3.1+, networkx>=2, pynauty

## Installation
The framework is majorly composed of metric extraction and graph learning components (based on [PSCN](https://github.com/tvayer/PSCN)).

### Metric generation component

```
    $ cd datagen
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
```

### Graph learning component
No additional step required. Users can choose to use the pynauty provided with the PSCN implementation.

```
    $ cd modelgen/pynauty-0.6.0
    $ make pynauty
    $ make user-ins pynauty
    $ pip install
```

## Train the model
To train the model with provided data:
```
python3 modelgen/train_model.py -l data/data1/labels_train.txt data/data1/train_input2/ -o [specify the path for saving the model, optional. default will be current location]
```

## Prediction (matching)
```
python3 modelgen/get_recom.py -l data/data1/labels_train.txt -v data/data1/labels_train.txt -m data/data1/static4_2_cfg_model.h5  data/data1/validate_input2
```

It will generate _pred\_results.csv_. To generate the matching summary, run:
```
python3 datagen/script/predAnalyzer data/data1/pred_results.csv
```

