#include <iostream>
#include <filesystem>
#include <string>
#include <set>

namespace fs = std::filesystem;

using std::cout; using std::endl;
using std::cerr;

using std::string;
using std::set;

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Usage: ./mod arg1 arg2 " << endl;
        cout << "\t arg1 is the name of folder to move from" << endl;
        cout << "\t arg2 is name of folder to move to" << endl;
        exit(1);
    }

    fs::path from = fs::current_path() / argv[1];
    fs::path to = fs::current_path() / argv[2];
    
    fs::rename(from, to);
    cout << "Renamed " << from << " to " << to << endl;

    set<char> problems;

    for (auto &p : fs::directory_iterator(to)) {
        string filename = p.path().filename().string();

        if (filename.size() <= 2 || filename[1] != '.') {
            cerr << "Unexpected filename format for filename: " << filename << endl;
            cerr << "(Expected filename to be longer than 2 characters, and expected a '.' as the second character)" << endl;
            exit(1);
        }
        
        auto ep = problems.emplace(filename[0]);
        if (ep.second) {
            fs::create_directory(to / filename.substr(0, 1));
            cout << "Created directory for problem " << filename[0] << endl;
        }

        int seconddot = filename.size();
        for (int i = filename.size() - 1; i >= 0; --i) {
            if (filename[i] == '.') {
                seconddot = i;
                break;
            }
        }

        if (seconddot == filename.size() || seconddot <= 1) {
            cerr << "Unexpected filename format for filename: " << filename << endl;
            cerr << "(Expected a second '.' to appear in the filename after the second character)" << endl;
            exit(1);
        }

        cout << "Renamed " << filename << " to ";
        filename.erase(1, seconddot - 1);
        cout << filename;

        fs::path newfileloc = to / filename.substr(0, 1) / filename;
        fs::rename(p.path(), newfileloc);
        cout << ", and moved it to " << newfileloc << endl;
    }

    cout << "Successfully rearranged files" << endl;
}

