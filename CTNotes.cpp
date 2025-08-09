#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


int help_menu(){


    std::string red = "\e[31m";
    std::string blue = "\e[0;34m";
    std::string green = "\e[0;32m";
    std::string reset = "\033[0m";
    std::cout << red << "Usage Example: ctnotes recon" << reset << std::endl;
    std::cout << std::endl;
    std::cout << blue << "-------------------------------------------------------------------------\n" << reset;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << green << "recon - [creates the recon.md file with pre-set notes]\n";
    std::cout << "dir  -  [creates a directory for a particular host with enumeration notes]\n";

    return 0;
}

int main(int argc, char* argv[]){


    if (argc <= 1){

        
        help_menu();
        
    } else{

        for(int i = 1; i < argc; ++i){
        std::string arg = argv[i];
        
        
        if (arg == "recon"){
            
            std::ofstream file("recon.md");
            if (file.is_open()){
                file << "<h1><font color='red'> NMap Scan </font></h1>" << std::endl;
                file << std::endl;
                file << std::endl;
                file << "   ";
                file << "<b><i><font color='violet'> Initial Scan </b></i></font>" << std::endl;
                file << std::endl;
                file << std::endl;
                file << "   ";
                file << "<b><i><font color='violet'> All Ports Scan </b></i></font>" << std::endl;
                file << std::endl;
                file << std::endl;
                file << "   ";
                file << "<b><i><font color='violet'> UDP Port Scan </b></i></font>" << std::endl;
                file << std::endl;
                file << std::endl;
                file << "   ";
                file << "<b><i><font color='violet'> Script Scan </b></i></font>" << std::endl;
        }
            }        
        else if(arg == "dir"){
            std::string directory;
            std::cout << "CTF Name: ";
            if(getline(std::cin, directory)){
                std::filesystem::create_directory(directory);
                std::string full_path = directory + "/enumeration.md";
                std::ofstream file2(full_path);
                file2 << "<h1><font color='red'> Directories Found </font></h1>" << std::endl;
                file2 << std::endl;
                file2 << std::endl;
                file2 << "<h1><font color='red'> WhatWeb </font></h1>" << std::endl;
                std::ofstream checklist(directory+"/checklist.md");
                if (checklist.is_open()){
                    checklist.close();
                }
                std::ofstream writeup(directory+"/writeup.md");
                if(writeup.is_open()){
                    writeup.close();
                }

            }
        }                

    }



    }


        
        

    





    return 0;

}