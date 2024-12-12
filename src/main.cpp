
#include "get_tbname.h"

int main() {
    std::vector<std::string> res_lst;
    std::string select_input = "SELECT t1.a, t1.b, t2.c FROM DB1.TB1 AS t1 JOIN (SELECT * FROM DB2.TB2 JOIN DB3.TB3 ON TB2.id = TB3.id) t2 ON t1.a = t2.b";
    std::string insert_input = "insert into BASIC_SHIP_INFORMATION_DB.SISTER_SHIP_INFO (SHIP_DATA_ID, SISTER_DATA_ID, SHIP_NAME) values (7082006, 7082007, 'test No1')";
    std::string update_input = "UPDATE db3.table3 SET column1 = 'value' WHERE column2 = 'key'";
    std::string delete_input = "DELETE FROM db4.table4 WHERE column1 = 'value'";
    if(sqltoaster::getTBName(delete_input, res_lst)) {
        for (auto& i : res_lst) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
