import sys,pickle,warnings
sys.path.append("/home/users/shravank/projects/meliora2/Meliora/scripts/")

from graph import Graph

def create_graph(matrix):

    #matrix format: \t\n
    matrix_body = matrix.body.strip().split('\n')

    print("Matrix_body: ",matrix_body)
    #matrix.id = None
    #matrix.label = None
    

    g = Graph()
    g.label = matrix.kernel_name
    g.kernel_name = "dev_"+matrix.file_name+".loop_"+matrix.loop_id+"@"+matrix.loop_cntrl+".matrix"
    g.loop_id = matrix.loop_id
    g.loop_cntrl = matrix.loop_cntrl

    for node_idx, line in enumerate(matrix_body):
        line_data = line.strip().split('\t')
        print("Line Data: ",line_data)
        node_attr = line_data[0]
        edge_list = line_data[1:]

        #print("Edge List: ", edge_list)

        #Add Vertex
        g.add_vertex(node_idx)

        #Add Edge and Edge Attributes: (vertex1,vertex2),edge_attr
        for edge_idx, edge in enumerate(edge_list):
            if float(edge) != 0.0:
                #print("Edge List added: ",(node_idx,edge_idx))
                g.add_edge((node_idx,edge_idx),weight=float(edge))
        
        #Add Node Attributes
        node_attr = node_attr.split(":")
        #print("Node_attr: ",node_attr)
        g.add_one_attribute(node_idx,node_attr)
        
        
    
    #Save graph as pickled object
    pickle.dump(g, open(g.kernel_name+".pkl","wb"))
    return g

class Matrix_Enum:

    def __init__(self):
        self.body = "0.00:50.00:50.00:0.00:5.00:0.00:0.00:0.00:0.00:0.00\t0.03\t0.97\t0.00\n7.26:72.64:0.11:19.98:5.00:0.00:0.00:66.93:33.07:0.00\t0.00\t0.00\t1.00\n0.00:50.00:25.00:25.00:5.00:100.00:0.00:0.00:0.00:0.00\t1.00\t0.00\t0.00"
        self.kernel_name = "mm"
        self.loop_name = "__orio_perftest4.c.loop_86@1.matrix"

        ##Ideal
        #graph.kernel_name
        #graph.kernel.version #relative to kernel
        #graph.kernel.version.variation
        #graph.kernel.version.loopID
        #graph.graph_label

        #Example
        #mm/__orio_perftest4.c.loop_86@1.matrix
        # 4 --> Version
        # loop_86 -->
        # @1 -->
 

if __name__ == "__main__":

    #hcfg is added to the main namespace from cfggen.cpp 
    matrix = hcfg
    print("Testing arrival of hcfg object")
    print("Matrix type: ",type(matrix))
    members = [attr for attr in dir(matrix) if not callable(getattr(matrix, attr)) and not attr.startswith("__")]
    print("Members of Matrix: ",members)
    print("matrix body: ",matrix.body)

    #g = Graph()
    #print("g: ",g)

    #sys.exit(0)

    #Receieve list of matrix objects from util.h/cfgpass.cpp via Boost
    matrix_objects = []
    #matrix = Matrix_Enum()
    print("matrix")
    print(matrix.body)
    #print("edge list: ",(0,0),(0,1),(1,2),(2,0))
    #sys.exit(0)

    #Temporary method to adjust string format
    #replaced = matrix.body.replace("\t\n","\n")
    #matrix.body = replaced

    matrix_objects.append(matrix)
    [create_graph(matrix) for matrix in matrix_objects]
   
    a = pickle.load(open("dev___orio_perftest13.c.loop_108@1.matrix.pkl","rb"))
    a = a.nx_graph
    print("Unpickleling: ")
    print("Graph: ",a)
    print("Nodes: ",[node for node in a.nodes()])
    print("Node Attributes: ",a.nodes(data="attr_name"))
    print("Edges: ",[edge for edge in a.edges()])
    print("Edge Data:", [a.get_edge_data(u,v) for u,v in a.edges()])
    
    print()
    print()
    print()
    #warnings.warn("STILL IN DEV MODE")
    #warnings.warn("Add edge attr to node attr?")


