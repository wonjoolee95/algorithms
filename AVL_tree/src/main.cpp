#include <iostream>
#include <fstream>
#include <vector>
#include "hashmap.hpp"
 
// Adds a link from the string "from" to the string "to"
void add_link_to_map(HashMap<std::string,std::vector<std::string>>& links, 
        std::string& from, std::string& to) 
{
    //TODO: Implement this method
    if (links.get(from) == links.get_default_value())
    {
        std::vector<std::string> temp;
        temp.push_back(to);
        links.set(from, temp);
    }
    else
    {
        std::vector<std::string> temp = links.get(from);
        temp.push_back(to);
        links.set(from, temp);
    }
}
 
int main() 
{
    std::string file_name = "data/wikipedia.txt";
    std::ifstream in_file(file_name);
     
    //Parse the links out of the text file
    std::string line;
    HashMap<std::string,std::vector<std::string>> links;
    while(std::getline(in_file,line)) 
    {
        std::string from = line.substr(0,line.find(","));
        std::string to = line.substr(line.find(",")+1);
        add_link_to_map(links,from,to);
    }
 
    std::cout<<"Which entry do you want to investigate?"<<std::endl;
    std::string entry;
    std::cin>>entry;
 
    std::cout<<"How many links do you want to follow?"<<std::endl;
    int n;
    std::cin>>n;
 
    // Set up a hashset to keep track of who we have printed out
    HashMap<std::string,bool> looked_at;
    looked_at.set(entry,true);
    // Keep track of the links from the previous level
    std::vector<std::string> previous_level;
    previous_level.push_back(entry);
 
    for(int i = 1; i <= n; i++) 
    {
        std::vector<std::string> current_level;
        // For each string in the previous level
        for(std::string s : previous_level) 
        {
            // For each of its links
            for(std::string s_link : links.get(s)) 
            {
                // If we haven't seen them before
                if(!looked_at.get(s_link)) 
                {
                    // Then they are at the current level
                    // Set them to be printed out and mark them as seen
                    current_level.push_back(s_link);
                    looked_at.set(s_link,true);
                }
            }
        }
         
        std::cout<<"The level "<<i<<" links are:"<<std::endl;
        for(std::string s : current_level) 
        {
            std::cout<<"  "<<s<<std::endl;
        }
        std::cout<<std::endl;
 
        // The current level's links are the next level's previous links
        previous_level = current_level;
    }
}
