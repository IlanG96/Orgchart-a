#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("level order String org")
{

   /*                                    CEO
       |---------------------|------------------------|----------------------|
  VP Product            VP Support             VP Marketing            VP Engineering
       |               |-----------|                                         |
    Senior PM   Support Rep1    Support Rep2                              Senior Engineer
       |                                                                      |
       PM                                                                Junior Engineer            
       |
    PM Intern                  1
 */
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO"));
        CHECK_NOTHROW(organization.add_sub("CEO", "VP Product"));    
        CHECK_NOTHROW(organization.add_sub("CEO", "VP Support"));    
        CHECK_NOTHROW(organization.add_sub("CEO", "VP Marketing"));   
        CHECK_NOTHROW(organization.add_sub("CEO", "VP Engineering"));  
        CHECK_NOTHROW(organization.add_sub("VP Product", "Senior PM"));
        CHECK_NOTHROW(organization.add_sub("VP Support", "Support Rep1"));
        CHECK_NOTHROW(organization.add_sub("VP Support", "Support Rep2"));
        CHECK_NOTHROW(organization.add_sub("VP Engineering", "Senior Engineer"));
        CHECK_NOTHROW(organization.add_sub("Senior Engineer", "Junior Engineer"));
        CHECK_NOTHROW(organization.add_sub("Senior PM", "PM"));
        CHECK_NOTHROW(organization.add_sub("PM", "PM Intern"));;   
    uint i = 0;
    vector<std::string> Corr_order = {"CEO", "VP Product", "VP Support", "VP Marketing", "VP Engineering", "Senior PM","Support Rep1","Support Rep2","Senior Engineer","PM","Junior Engineer","PM Intern"};
    for (auto it = organization.begin(); it != organization.end(); ++it) {
    i++;   
    CHECK_EQ(Corr_order.at(i), (*it));
    } 
}


TEST_CASE("pre order")
{
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("6"));
    CHECK_NOTHROW(organization.add_sub("6", "5"));    
    CHECK_NOTHROW(organization.add_sub("6", "4"));    
    CHECK_NOTHROW(organization.add_sub("6", "3"));   
    CHECK_NOTHROW(organization.add_sub("5", "2"));  
    CHECK_NOTHROW(organization.add_sub("3", "1"));
/*              1
       |--------|--------|
       2        6        7
       |               |------|
       3               8      9
       |
       4
       |
       5                 
 */
    size_t i = 0;
    vector<std::string> Corr_order = {"1", "2", "3", "4", "5", "6","7","8","9"};
    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it) {
    CHECK_EQ(Corr_order.at(i++), (*it));
    } 
}

TEST_CASE("reverse level iterator")
{
    /*
    This tests the correctness of reverse level iterator
    */
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("8"));
    CHECK_NOTHROW(organization.add_sub("8", "5"));    
    CHECK_NOTHROW(organization.add_sub("8", "6"));    
    CHECK_NOTHROW(organization.add_sub("8", "7"));   
    CHECK_NOTHROW(organization.add_sub("5", "2"));  
    CHECK_NOTHROW(organization.add_sub("6", "3"));
    CHECK_NOTHROW(organization.add_sub("7", "3"));
    CHECK_NOTHROW(organization.add_sub("4", "1"));
/*              8
       |--------|--------|
       5        6        7
        |        |        |
        2        3        4
                          |
                          1
 */
    uint i = 0;
    vector<std::string> Corr_order = {"1", "2", "3", "4", "5", "6","7","8"};
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
    CHECK_EQ(Corr_order.at(i++), (*it));
    } 
}

TEST_CASE("Errors test"){
    OrgChart Fail_org;
    Fail_org.add_root("1");
    CHECK_THROWS(Fail_org.add_sub("2","3"));//no "2" in this tree
    CHECK_NOTHROW(Fail_org.add_sub("1","2"));
    CHECK_THROWS(Fail_org.add_sub("1","1"));//"1" already in the tree
    CHECK_NOTHROW(Fail_org.add_sub("2","3"));
    CHECK_THROWS(Fail_org.add_sub("2","3"));// cant add the same sub twice

}