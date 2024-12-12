
#include "get_tbname.h"

int main() {
    std::vector<std::string> res_lst;
    std::string input = "SELECT t1.a, t1.b, t2.c FROM DB1.TB1 AS t1 JOIN (SELECT * FROM DB2.TB2 JOIN DB3.TB3 ON TB2.id = TB3.id) t2 ON t1.a = t2.b";
    if(getTBName(input, res_lst)) {
        for (auto& i : res_lst) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
