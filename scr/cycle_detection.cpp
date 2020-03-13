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
    std::vector<std::vector<int>> cn_neighbors = find_cn_neighbors(input_matrix);
    std::vector<std::vector<int>> vn_neighbors = find_vn_neighbers(input_matrix);
    std::vector<std::vector<int>> parents_pairs; //{[0]: grandparents,[1]: parents}
    std::vector<std::vector<int>> kids_paris;    //{[0]: grandparents, [1]: parents}
    std::vector<int> vari_hash_mapping(col_len), check_hash_mapping(row_len);
    for (int ii = 0; ii < col_len; ii++)
    {
        vari_hash_mapping[ii] = ii;
    }
    for (int jj = 0; jj < row_len; jj++)
    {
        check_hash_mapping[jj] = jj + col_len;
    }
    for (int cur_int= start_ind; cur_int<=end_ind; cur_int++)
    {
        
    }
}