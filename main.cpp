//#define ENABLE_TRACE
#include <iostream>
#include <string>
#include <chrono>
#include <chrpp.hh>
#include "include/AnySimpleType.h"
#include "include/parsercowl.h"

#include "include/constants.h"
#include "include/types.h"
#include "include/chr_traits.h"
#include "include/utils.h"
#include "owlrules.hpp"

// ── Store printer ─────────────────────────────────────────────────────────────

template <typename T>
void print(T& pb) {
    auto it = pb.chr_store_begin();
    while (!it.at_end()) {
        std::cout << it.to_string() << std::endl;
        ++it;
    }
}

int main(int argc, char* argv[])
{

     std::ofstream fileReal(output_file_Real);
     std::ofstream fileClassif(output_file_Classif);
     std::ofstream fileQuery(output_file_Queries);
     
   // Déterminer le fichier à utiliser
    std::string filename = "results/OWL2RL-1.ofn"; // Valeur par défaut

    if (argc > 1) {
        filename = argv[1];
    }

    auto start =std::chrono::steady_clock::now();
    auto space = OWL2::create();
 CHR_RUN(
    chr::Logical_var<int> owlThingLogicalVar;
    chr::Logical_var<int> owlNothingLogicalVar;
    space->logicalName(owlThing, owlThingLogicalVar);
    space->logicalName(owlNothing, owlNothingLogicalVar);
    ParserCowl<OWL2> parser(filename, *space);
    parser.load();


   // space->querySuperClassOfUri(std::string("http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#TA"));
    space->queryObjAssertionUri(std::string("<https://kracr.iiitd.edu.in/OWL2Bench#isMemberOf>"));
    space->queryObjAssertionUri(std::string("<https://kracr.iiitd.edu.in/OWL2Bench#isPartOf>"));
    space->realisation();
    space->classification();
    // space->queryObjAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#isMemberOf"));
    // space->queryObjAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#isPartOf"));
    // space->queryDataAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#hasAge"));
    // space->queryInstancesURI(std::string("https://kracr.iiitd.edu.in/OWL2Bench#T20CricketFan"));
    // space->queryObjAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#hasAlumnus"));
    // space->queryObjAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#isAffiliatedOrganizationOf"));
    // space->queryObjAssertionSubjectUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#hasCollegeDiscipline"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#NonScience"));
    // space->queryObjAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#hasCollaborationWith"));
    // space->queryObjAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#isAdvisedBy"));
    // space->queryInstancesURI(std::string("https://kracr.iiitd.edu.in/OWL2Bench#Person"));
    // space->queryInstancesURI(std::string("https://kracr.iiitd.edu.in/OWL2Bench#WomanCollege"));
    // space->queryInstancesURI(std::string("https://kracr.iiitd.edu.in/OWL2Bench#LeisureStudent"));
    // space->querySubjectByObjectUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#isHeadOf"));
    // space->querySubjectByObjectUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#hasHead"));
    // space->queryInstancesURI(std::string("https://kracr.iiitd.edu.in/OWL2Bench#Faculty"));
    // space->queryObjAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#hasSameHomeTownWith"));
    // space->queryEngineeringStudentsUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#Student"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#isStudentOf"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#isPartOf"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#hasCollegeDiscipline"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#Engineering"));
    // space->queryComplexStudentsUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#Student"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#Organization"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#hasDean"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#teachesCourse"),std::string("https://kracr.iiitd.edu.in/OWL2Bench#takesCourse"));
    
    //  for (auto& c : space-> get_queryObjAssertion_store())
    //     std::cout << "  " << *std::get<2>(c) << std::endl;
 )
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout<<"temps "<<  elapsed.count()  <<std::endl;
    print(*space);
    //chr::Statistics::print(std::cout);

    return 0;
}