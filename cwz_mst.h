#ifndef CWZ_MST_H
#define CWZ_MST_H

#include "cwz_non_local_cost.h"

typedef uchar TEleUnit;

class cwz_mst{
public:
	cwz_mst():isInit(false), hasImg(false){}
	void init(int _h, int _w, int _ch);
	void set_img(TEleUnit *_img);
	void build_edges();
	void counting_sort();
	void kruskal_mst();
	void build_tree();
	void mst();
	//profiling
	void profile_mst();
	//for reuse
	void reinit();
	//test use function
	void test_correctness();
private:
	bool isInit;
	bool hasImg;

	TEleUnit *img;
	short *distance;
	int **edge_node_list;//[2]edge��ݪ�node��idx
	int *cost_sorted_edge_idx;
	int *node_group;
	
	int **node_conn_node_list;//[4]�Ҧ��P��node�۳s��node(�����s�bedge���t�@���I)
	int **node_conn_weights;  //[4]�O���Q�s����edge��weight
	int *node_conn_node_num;  //�O��node_conn_node_list�����X���I���I�s��

	int histogram[IntensityLimit];

	int *id_stack;//node index
	int id_stack_e;
	int *node_parent_id;

	//�̲׭n�ϥΪ� tree ���c
	int **child_node_list;
	int *node_weight;//weight on the edge with its parent ( root's weight will be -1 )
	int *node_idx_from_p_to_c;//node id from parent to children

	int h, w;
	int edge_amt;
	int node_amt;
	int channel;
};

#endif