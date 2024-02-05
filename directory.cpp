/*
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<sstream>
#include<cstring>

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
#define MAX 50001
typedef long long ll;
using namespace std;

#define CMD_MKDIR 1
#define CMD_RM 2
#define CMD_CP 3
#define CMD_MV 4
#define CMD_FIND 5

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

extern void init(int n);

extern void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]);

extern void cmd_rm(char path[PATH_MAXLEN + 1]);

extern void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]);

extern void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]);

extern int cmd_find(char path[PATH_MAXLEN + 1]);

static bool run(int m) {

    bool isAccepted = true;
    int cmd;
    char name[NAME_MAXLEN + 1];
    char path1[PATH_MAXLEN + 1], path2[PATH_MAXLEN + 1];

    while (m--) {

        scanf("%d", &cmd);

        if (cmd == CMD_MKDIR) {
            scanf("%s%s", path1, name);
            cmd_mkdir(path1, name);
        } else if (cmd == CMD_RM) {
            scanf("%s", path1);
            cmd_rm(path1);
        } else if (cmd == CMD_CP) {
            scanf("%s%s", path1, path2);
            cmd_cp(path1, path2);
        } else if (cmd == CMD_MV) {
            scanf("%s%s", path1, path2);
            cmd_mv(path1, path2);
        } else {
            int ret;
            int answer;

            scanf("%s", path1);
            ret = cmd_find(path1);
            scanf("%d", &answer);
//            cout << "find_result = " << ret << " " << answer << "\n";


            isAccepted &= (ret == answer);
        }
    }

    return isAccepted;
}

int main(void) {

    int test, T;
    int n, m;

    // freopen("sample_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test = 1; test <= T; ++test) {

        scanf("%d%d", &n, &m);

        init(n);

        if (run(m)) {
            printf("#%d 100\n", test);
        } else {
            printf("#%d 0\n", test);
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define PATH_MAXLEN 1999

struct Directory {
    int subDirectoryCount;
    long long directoryNameHash;
    array<int, 30> childIndices;
    int childCount;
    int parentIndex;
    Directory() { }
    Directory(long long nameHash) {
        this->directoryNameHash = nameHash;
        subDirectoryCount = 0;
    }
};

Directory directoryPool[50'050];
int poolPointer = 0;
int rootIndex;

int createDirectory(long long nameHash) {
    Directory &newDirectory = directoryPool[poolPointer++];
    newDirectory.directoryNameHash = nameHash;
    newDirectory.subDirectoryCount = 0;
    newDirectory.childCount = 0;
    newDirectory.parentIndex = -1;
    return poolPointer - 1;
}

int cloneDirectory(int targetIndex) {
    int cloneIndex = createDirectory(directoryPool[targetIndex].directoryNameHash);
    Directory &clone = directoryPool[cloneIndex];
    clone.subDirectoryCount = directoryPool[targetIndex].subDirectoryCount;
    clone.parentIndex = -1;
    clone.childCount = 0;
    for (int i = 0; i < directoryPool[targetIndex].childCount; ++i) {
        int childCloneIndex = cloneDirectory(directoryPool[targetIndex].childIndices[i]);
        clone.childIndices[clone.childCount++] = childCloneIndex;
        directoryPool[childCloneIndex].parentIndex = cloneIndex;
    }
    return cloneIndex;
}

void init(int n) {
    poolPointer = 0;
    rootIndex = createDirectory(0);
}

int convertPathToDirectoryIndex(char path[PATH_MAXLEN + 1]) {
    int currentDirectoryIndex = rootIndex;
    for (int i = 1; path[i]; ) {
        int pathPosition = i;
        long long directoryNameHash = 0;
        while (path[pathPosition] != '/') {
            directoryNameHash <<= 5;
            directoryNameHash += (path[pathPosition] - 'a' + 1);
            ++pathPosition;
        }
        int left = 0, right = directoryPool[currentDirectoryIndex].childCount - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (directoryPool[directoryPool[currentDirectoryIndex].childIndices[mid]].directoryNameHash >= directoryNameHash) right = mid;
            else left = mid + 1;
        }
        currentDirectoryIndex = directoryPool[currentDirectoryIndex].childIndices[right];
        i = pathPosition + 1;
    }
    return currentDirectoryIndex;
}

inline void insertChild(array<int, 30> &children, int &childCount, int childIndex) {
    children[childCount++] = childIndex;
    for (int i = childCount - 2; i >= 0; --i) {
        if (directoryPool[children[i]].directoryNameHash > directoryPool[children[i + 1]].directoryNameHash) swap(children[i], children[i + 1]);
        else break;
    }
}

void updateParentSubdirectoryCount(int directoryIndex, int delta) {
    while (directoryIndex != -1) {
        directoryPool[directoryIndex].subDirectoryCount += delta;
        directoryIndex = directoryPool[directoryIndex].parentIndex;
    }
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
    int parentIndex = convertPathToDirectoryIndex(path);
    updateParentSubdirectoryCount(parentIndex, 1);
    long long nameHash = 0;
    for (int i = 0; name[i]; ++i) {
        nameHash <<= 5;
        nameHash += (name[i] - 'a' + 1);
    }
    int newDirectoryIndex = createDirectory(nameHash);
    insertChild(directoryPool[parentIndex].childIndices, directoryPool[parentIndex].childCount, newDirectoryIndex);
    directoryPool[newDirectoryIndex].parentIndex = parentIndex;
}

void removeDirectoryByIndex(int directoryIndex) {
    int parentIndex = directoryPool[directoryIndex].parentIndex;

    // 이진 탐색으로 자식 목록에서 삭제할 디렉토리의 인덱스를 찾습니다.
    int left = 0, right = directoryPool[parentIndex].childCount - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (directoryPool[directoryPool[parentIndex].childIndices[mid]].directoryNameHash >= directoryPool[directoryIndex].directoryNameHash) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    // 찾은 인덱스 이후의 모든 자식들을 한 칸씩 앞으로 이동시킵니다.
    for (int i = right; i < directoryPool[parentIndex].childCount - 1; ++i) {
        directoryPool[parentIndex].childIndices[i] = directoryPool[parentIndex].childIndices[i + 1];
    }

    // 부모 디렉토리의 자식 수를 감소시킵니다.
    --directoryPool[parentIndex].childCount;
    updateParentSubdirectoryCount(parentIndex, -(directoryPool[directoryIndex].subDirectoryCount + 1));
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
    int directoryIndex = convertPathToDirectoryIndex(path);
    removeDirectoryByIndex(directoryIndex);
}


void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    int srcIndex = convertPathToDirectoryIndex(srcPath);
    int dstIndex = convertPathToDirectoryIndex(dstPath);
    updateParentSubdirectoryCount(dstIndex, directoryPool[srcIndex].subDirectoryCount + 1);
    int cloneIndex = cloneDirectory(srcIndex);
    insertChild(directoryPool[dstIndex].childIndices, directoryPool[dstIndex].childCount, cloneIndex);
    directoryPool[cloneIndex].parentIndex = dstIndex;
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    int srcIndex = convertPathToDirectoryIndex(srcPath);
    int dstIndex = convertPathToDirectoryIndex(dstPath);
    updateParentSubdirectoryCount(dstIndex, directoryPool[srcIndex].subDirectoryCount + 1);
    cmd_rm(srcPath);
    insertChild(directoryPool[dstIndex].childIndices, directoryPool[dstIndex].childCount, srcIndex);
    directoryPool[srcIndex].parentIndex = dstIndex;
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
    return directoryPool[convertPathToDirectoryIndex(path)].subDirectoryCount;
}
*/
