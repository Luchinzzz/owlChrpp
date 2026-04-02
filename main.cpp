// #define ENABLE_TRACE
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
#include "owlrulesOWL2.hh"

// ── Store printer ─────────────────────────────────────────────────────────────

template <typename T>
void print(T &pb)
{
    auto it = pb.chr_store_begin();
    while (!it.at_end())
    {
        std::cout << it.to_string() << std::endl;
        ++it;
    }
}

std::vector<Query> queries = {
    // Superclass query: Retrieves all superclasses of a class PhD_Student
    {"super", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#PhD_Student>"},

    // Superclass query: retrieve all individuals classified as Lecturer
    //{"sub", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#Lecturer>"},

    // Superclass query: retrieve all individuals classified as TA
    //{"super", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#TA>"},

    // Object property query: retrieve all (subject, object) pairs of is_studying
    {"obj", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#is_studying>"},

    // Object property query: retrieve all (subject, object) pairs of offered_by
    {"obj", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#offered_by>"},

    // Object property query: retrieve all (subject, object) pairs of belonging_to
    {"obj", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#belonging_to>"},

    // Object property query: retrieve all (subject, object) pairs of lecturers_of_faculty
    {"obj", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#lecturers_of_faculty>"},

    // Data property query: retrieve all (subject, value) pairs of grade
    {"data", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#grade>"},

    // Data property query: retrieve all (subject, value) pairs of name
    {"data", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#name>"},

    // Data property query: retrieve all (subject, value) pairs of course_code
    {"data", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#course_code>"},


    {"inst", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#Student>"},

    {"inst", "<http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#TA>"},
};

int main(int argc, char *argv[])
{
    create_output_dirs();
    std::ofstream fileReal(output_file_Real);
    std::ofstream fileClassif(output_file_Classif);

    // Déterminer le fichier à utiliser
    std::string filename = "examples/ofn/OWL2RL-11.ofn"; // Valeur par défaut

    if (argc > 1)
    {
        filename = argv[1];
    }

    auto start = std::chrono::steady_clock::now();
    auto space = OWL2::create();
    CHR_RUN(
        chr::Logical_var<int> owlThingLogicalVar;
        chr::Logical_var<int> owlNothingLogicalVar;
        space->logicalName(owlThing, owlThingLogicalVar);
        space->logicalName(owlNothing, owlNothingLogicalVar);
        ParserCowl<OWL2> parser(filename, *space);
        parser.load();

        int counter = 0;

 
        for (const auto &q : queries) {
            if (q.type == "obj")
            {
                space->queryObjAssertionUri(q.uri);
            }
            else if (q.type == "super")
            {
                space->querySuperClassOfUri(q.uri);
            }
            else if (q.type == "data")
            {
                space->queryDataAssertionUri(q.uri);
            }
            else if (q.type == "subj")
            {
                // querySubjectByObjectUri
                space->querySubjectByObjectUri(q.uri);
            }
            // else if (q.type == "obj-subject")
            // {
            //     // obj assertion con soggetto specifico
            //     space->queryObjAssertionSubjectUri(q.uri);
            // }
            else if (q.type == "inst")
            {
                // queryInstancesURI
                space->queryInstancesURI(q.uri);
            }
            else
            {
                std::cerr << "Type of query not recognized: " << q.type << std::endl;
                continue;
            }
        };


        // space->querySuperClassOfUri(std::string("http://www.semanticweb.org/midos/ontologies/2022/11/untitled-ontology-14#TA"));
        // space->queryObjAssertionUri(std::string("<https://kracr.iiitd.edu.in/OWL2Bench#isMemberOf>"));
        // space->queryObjAssertionUri(std::string("<https://kracr.iiitd.edu.in/OWL2Bench#isPartOf>"));
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
    std::cout << "Elapsed time: " << elapsed.count() << std::endl;
    // print(*space);
    // chr::Statistics::print(std::cout);

    return 0;
}
