#include <vcl_fstream.h>

#include <vtol/vtol_vertex_2d_ref.h>
#include <vtol/vtol_vertex_2d.h>
#include <vsol/vsol_point_2d.h>
#include <vtol/vtol_edge.h>
#include <vtol/vtol_edge_ref.h>
#include <vtol/vtol_edge_2d.h>
#include <vtol/vtol_edge_2d_ref.h>

#include <vtol/vtol_zero_chain_ref.h>
#include <vtol/vtol_zero_chain.h>



#define Assert(x) do { if (x) vcl_cerr << "test PASSED\n"; else vcl_cerr << "test FAILED [" #x "]\n"; } while (0)


int main(int, char **)
{
  vcl_cerr << "testing edge 2d" << endl;

  vtol_vertex_2d_ref v1 = new vtol_vertex_2d(0.0,0.0);
  vtol_vertex_2d_ref v2 = new vtol_vertex_2d(1.0,1.0);
  vtol_vertex_2d_ref v3 = new vtol_vertex_2d(2.0,2.0);
  vtol_vertex_2d_ref v4 = new vtol_vertex_2d(3.0,3.0);
  
 
  vtol_edge_2d_ref e1= new vtol_edge_2d(*v1,*v2);
  vtol_edge_2d_ref e1a = new vtol_edge_2d(*e1);
  
  

  Assert(*e1==*e1a);

  vtol_zero_chain_ref zc2 = new vtol_zero_chain(*v2,*v3);

  vtol_edge_2d_ref e2 = new vtol_edge_2d(*zc2);

  vtol_zero_chain_ref zc3 = new vtol_zero_chain(*v3,*v4);

  zero_chain_list z_list;
   
  z_list.push_back(zc3);
  
  
  z_list.push_back(zc2);


  
  vtol_edge_2d_ref e3 = new vtol_edge_2d(z_list);

  

  vtol_edge_2d_ref e4 = new vtol_edge_2d(3.0,3.0,4.0,4.0);

  vtol_edge_2d_ref e4_clone = e4->clone()->cast_to_topology_object()->cast_to_edge()->cast_to_edge_2d();


  Assert(*e4 == *e4_clone);
  
  Assert(!(*e4==*e1));
  
  Assert(*e4==*(e4_clone->cast_to_topology_object()));
  
  Assert(e4->cast_to_edge_2d()!=0);
  
  Assert(e4->compare_geometry(*e4_clone));

  Assert(*e4== *(e4_clone->cast_to_topology_object()));

  Assert(!e4->compare_geometry(*e1));
  
  Assert(e1->topology_type()==vtol_topology_object::EDGE);
  

  vtol_vertex_ref e1v1 = e1->v1();
  vtol_vertex_ref e1v2 = e1->v2();
  
  Assert(*e1v1==*v1);
  Assert(*e1v2==*v2);
  
  vtol_zero_chain_ref e2zc = e2->zero_chain();
  Assert(*e2zc==*zc2);
  
  e1->set_v1(v3->cast_to_vertex());

  e1->set_v2(v4->cast_to_vertex());
  
  Assert(*(e1->v1())==*v3);
  Assert(*(e1->v2())==*v4);
  
  
  vtol_vertex_ref current = e1->v1();

  e1->replace_end_point(*current,*(v1));

  Assert(*(e1->v1())==*v1);


  Assert(e1->cast_to_edge()!=0);
  

  vcl_cerr << "finished testing edge 2d" << endl;
  return 0;
}

