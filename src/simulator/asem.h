#ifndef _ASEM_H_
#define _ASEM_H_
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include "hash.h"
#include "triple.h"
using namespace std;
//表示Asem的ivec有效
#define type_is_vector 0

//表示Asem的name有效
//表示没有引号的string，可能是关键词，操作符等
#define type_is_string1 1
//表示有引号的string
#define type_is_string2 2


class Asem{
 private:
  void eval_unfold(vector<string> &var_name,
		   vector<vector<string> >&var_choose_name,
		   vector<vector<int> >&var_val,
		   vector<pair<int,int> > &var_choosed_val,
		   Asem &code,
		   Asem &binary,
		   Asem * doo,
		   vector<triple> &r);
  void dfs_unfold_instr(vector<string> &var_name, // 变量名字
			vector<vector<string> > &var_choose_name, // 变量可选的值的名字
			vector<vector<int> > &var_val,		// 变量可选值对应unfolded_list的索引
			vector<pair<int,int> > &var_choosed_val,	// 变量取值的情况
			Asem &code,				// 待展开的code对应asem
			Asem &binary,				// 待展开的binary对应asem
			Asem * doo,				// 待展开do对应的asem
			int lev,					// 当前枚举到第lev个变量
			vector<triple> &r);			// 保存展开结果
  int unfold_enum();
  int unfold_type();
  int unfold_instr();
  void switch_chg(vector<string> &var_name,
		  vector<vector<string> >&var_choose_name,
		  vector<vector<int> >&var_val,
		  vector<pair<int,int> > &var_choosed_val
		  );
  void dfs_copy_content(do_content &dl);
 public:
  /*TODO chang following member to private*/
  static hash_control & hc_unfold;
  static vector<vector<triple > > & unfolded_list;
  static vector<string> & unfolded_list_name;// name of rule of corresponding unfolded_list
  static class hash_control & hc;
  vector<Asem> ivec;
  string name;
  int type;
  //用于保存do的数据结构
  //vector<Asem*> do_list;
  // 哈希表 hash controller
  
  bool is_instr(string name);
  bool is_type(string name);
  bool is_enum(string name);
  Asem *get_asem(string name);
  string get_full_name(string name,string pwd);
  void dfs_insert_hash(string pwd);
  Asem * find(const string &name);
  void display(int lev);// output content in ivec recursively
  void gen(FILE * &input);// read from file
  int unfold();// analysize conten in ivec
};
#endif
