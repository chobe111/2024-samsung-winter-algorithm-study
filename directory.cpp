//
// Created by myungki cho on 2024/02/02.
//

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<sstream>

#define MAX 50001
using namespace std;

class FileSystem {
private:
    struct Directory {
        int parent_directory;
        // child name, directory index
        unordered_map<int, int> child_directory_map;
        int num;
        int size;

        void add_child(int name, int directory_num) {
            child_directory_map.insert({name, directory_num});
        }

        int find_child(int directory_num) {
            auto find_info = child_directory_map.find(directory_num);
            if (find_info == child_directory_map.end()) return 0;
            return find_info->second;
        }

        void remove_child(int name) {
            child_directory_map.erase(name);
        }
    };

    inline int name_to_integer(string name) {
        int ret = 0;
        for (int i = 0; i < name.size(); i++) {
            if (name[i] == '\0') continue;
            ret += pow(26, i) * int(name[i] - 'a');
        }
        return ret;
    }


    vector<int> get_path_info(char path[2000]) {
        vector<int> ret;
        string sub_string;
        istringstream ss(path);

        while (getline(ss, sub_string, '/')) {
            ret.push_back(name_to_integer(sub_string));
        }
        return ret;
    }

public:
    int directory_cnt;
    Directory directories[MAX];

    Directory getDirectory(int parentIndex) {
        Directory newDirectory = directories[directory_cnt++];
        newDirectory.num = directory_cnt;
        newDirectory.parent_directory = parentIndex;

        return newDirectory;
    }

    FileSystem() {
        Directory rootDirectory = getDirectory(-1);
    }

    // O(1200)
    void make_directory(char path[2000], char name[7]) {
        vector<int> path_list = get_path_info(path);
        int newName = name_to_integer(name);
        Directory newDirectory = getDirectory(0);
        Directory curDirectory = directories[0];
        for (int i = 1; i < path_list.size(); i++) {
            directories[curDirectory.find_child(path_list[i])].size += 1;
        }
        curDirectory.add_child(newName, newDirectory.num);
        newDirectory.parent_directory = curDirectory.num;
    }

    void remove_directory(char path[2000]) {
        vector<int> path_list = get_path_info(path);
        Directory curDirectory = directories[0];
        for (int i = 1; i < path_list.size(); i++) {
            curDirectory = directories[curDirectory.find_child(path_list[i])];
        }
        directories[curDirectory.parent_directory].remove_child(path_list[path_list.size() - 1]);
        int removeSize = curDirectory.size;

        curDirectory = directories[0];
        for (int i = 1; i < path_list.size(); i++) {
            curDirectory.size -= removeSize;
            curDirectory = directories[curDirectory.find_child(path_list[i])];
        }
    }

    // O(1200)
    void copy_directory(char srcPath[2000], char targetPath[2000]) {
        vector<int> src_path_list = get_path_info(srcPath);
        vector<int> target_path_list = get_path_info(targetPath);

        Directory srcCurDirectory = directories[0];
        Directory tarCurDirectory = directories[0];
        for (int i = 1; i < src_path_list.size(); i++) {
            srcCurDirectory = directories[srcCurDirectory.find_child(src_path_list[i])];
        }

        for(int i = 1; i < target_path_list.size(); i++) {
            tarCurDirectory = directories[tarCurDirectory.find_child(target_path_list[i])];
        }

        int srcCurDirectoryName = src_path_list[src_path_list.size()-1];
        tarCurDirectory.add_child(srcCurDirectoryName, srcCurDirectory.num);
    }

    // O(1200)
    void move_directory() {

    }

    // O(1)
    int get_descendant_nums(char path[2000]) {
        Directory curDirectory = directories[0];
        vector<int> path_list = get_path_info(path);
        for (int i = 1; i < path_list.size(); i++) {
            curDirectory = directories[curDirectory.find_child(path_list[i])];
        }
        return curDirectory.size;
    }
};


int main() {


    return 0;
}