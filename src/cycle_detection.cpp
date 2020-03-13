#include "cycle_detection.h"




std::vector<std::vector<int>> find_cn_neighbors(std::vector<std::vector<int>> & input_matrix)
{
    /*
    This function finds all variable nodes connect to each check node
    if one check node currently does not conncet variable node
    we will also keep a position to this check node 
    but vector size will be empet, i.e., 0 
    */
   std::vector<std::vector<int>> cn_neighbor(input_matrix.size());
   unsigned vari_num = input_matrix[0].size();
   for (unsigned ii=0; ii< cn_neighbor.size() ; ii++)
   {
       cn_neighbor[ii].clear();
       for (unsigned jj=0;jj<vari_num;jj++)
       {
           if(input_matrix[ii][jj]!=0)
           {
               cn_neighbor[ii].push_back(jj);
           }
       }
   }
   return cn_neighbor;
}

std::vector<std::vector<int>> find_vn_neighbers(std::vector<std::vector<int>> & input_matrix)
{
    /*
    find all check nodee connets to each variable node
    rule is same to find_cn_neighbors 
    */
   unsigned vari_num = input_matrix[0].size();
   unsigned check_num = input_matrix.size();
   std::vector<std::vector<int>> vn_neighbers(vari_num);
   for (unsigned ii=0 ;ii< vari_num;ii++)
   {
       vn_neighbers[ii].clear();
       for (unsigned jj=0;jj<check_num;jj++)
       {
           if(input_matrix[jj][ii]!=0)
           {
               vn_neighbers[ii].push_back(jj);
           }
       }
   }
   return vn_neighbers;

}

bool Cycle_Detection(std::vector<std::vector<int>>& input_matrix, int start_ind, int end_ind, int max_cycle)
{
    // This function simply gives you if your parity check matrix have cycles less than you want to check
    // For example, if you want to check if your parity check matrix have cycles less than 6 , you input max
    // max_cycle as 6, if there is no cycle less than or equal to 4, this program returns true.
    // However, if ther is cycle length 6 ,4 ,2. Then a false will be returned
    if (max_cycle%2==1)
    {
        std::cout<<"Info: parameter max_cycle must be an even number. exit..."<<std::endl;
        return false;
    }

    int row_len = (int)input_matrix.size();
    int col_len = (int)input_matrix[0].size();
    std::vector<bool> Hash(row_len + col_len, false);
    int layer = max_cycle / 2;
    int cur_layer;
    int cur_parent;
    int cur_grandparent;
    std::vector<int> kids_list;
    std::vector<std::vector<int>> cn_neighbors = find_cn_neighbors(input_matrix);
    std::vector<std::vector<int>> vn_neighbors = find_vn_neighbers(input_matrix);
    std::vector<std::vector<int>> parents_pairs; //{[0]: grandparents,[1]: parents}
    std::vector<std::vector<int>> kids_paris;    //{[0]: parents, [1]: kids}
    std::vector<int> vari_hash_mapping(col_len), check_hash_mapping(row_len);
    for (int ii = 0; ii < col_len; ii++)
    {
        vari_hash_mapping[ii] = ii;
    }
    for (int jj = 0; jj < row_len; jj++)
    {
        check_hash_mapping[jj] = jj + col_len;
    }
    for (int cur_ind= start_ind; cur_ind<=end_ind; cur_ind++)
    {
        // Initialization 
        Hash.assign(row_len+col_len, false);
        Hash[vari_hash_mapping[cur_ind]]=true;
        kids_paris.clear();
        parents_pairs.clear();
        parents_pairs.push_back({-1, cur_ind });
        for (cur_layer = 0 ;cur_layer<layer; cur_layer++)
        {
            // cur_layer == even -> parents are vari node and kids/gp are check node 
            // cur_layer == odd  -> parents are check node and kids/gp are vari node 
            for (unsigned jj =0 ; jj<parents_pairs.size();jj++)
            {
                cur_parent = parents_pairs[jj][1];
                cur_grandparent = parents_pairs[jj][0];
                if(cur_layer%2==0)
                {
                    kids_list = vn_neighbors[cur_parent];
                }
                else
                {
                    kids_list = cn_neighbors[cur_parent];
                }
                std::cout << "kid list----" << std::endl;
                display(kids_list);
                std::cout << "---" << std::endl;
                for (unsigned jj = 0; jj < kids_list.size(); jj++)
                {
                    if (cur_layer % 2 == 0)
                    {
                        if (kids_list[jj] != cur_grandparent)
                        {
                            if (check_hash_mapping[kids_list[jj]] == true)
                            {
                                std::cout << "Info: Exsit Cycle less than or equal to " << max_cycle << "." << std::endl;
                                return false;
                            }
                            else
                            {
                                kids_paris.push_back({cur_parent, kids_list[jj]});
                            }
                        }
                    }
                    else
                    {

                        if (kids_list[jj] != cur_grandparent)
                        {
                            if (vari_hash_mapping[kids_list[jj]] == true)
                            {
                                std::cout << "Info: Exsit Cycle less than or equal to " << max_cycle << "." << std::endl;
                                return false;
                            }
                            else
                            {
                                kids_paris.push_back({cur_parent, kids_list[jj]});
                            }
                        }
                    }
                }
            }
            for (unsigned ii = 0; ii < kids_paris.size(); ii++)
            {
                std::cout<<kids_paris[ii][1]<<" ";
            }
            std::cout<<std::endl;
            parents_pairs=kids_paris;
            kids_paris.clear();
        }
    }
    std::cout<<"Info: No cycles less than or equal to "<<max_cycle<<" exits." <<std::endl;
    return true;

}

void display(std::vector<int> input)
{
    for(const auto aa:input)
        std::cout<<aa<<" ";
    std::cout<<std::endl;
}