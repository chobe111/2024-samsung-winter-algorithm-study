//
// Created by myungki cho on 2024/02/05.
//

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<functional>
#include<cstring>
#include<set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

map<int, int> grade_match_info = {
        {1,   0},
        {2,   1},
        {3,   2},
        {12,  3},
        {13,  4},
        {23,  5},
        {123, 6}
};

map<int, int> gender_match_info = {
        {0,  1},
        {1,  2},
        {10, 3}
};

map<int, piii> mid_score_info;
// score, mid 집합
set<pair<int, int>> total_set[22];

int get_grade_set_num(int grade_cnt, int grade_arr[]) {
    sort(grade_arr, grade_arr + grade_cnt);
    int ret = 0;
    for (int i = 0; i < grade_cnt; i++) {
        int multi = 1;
        int multi_cnt = grade_cnt - i - 1;
        while (multi_cnt) {
            multi *= 10;
            multi_cnt--;
        }
        ret += multi * grade_arr[i];
    }
    return grade_match_info[ret];
}

int get_gender_set_num(int gender_cnt, char gender_arr[][7]) {
    vector<int> vec;
    for (int i = 0; i < gender_cnt; i++) {
        if (strcmp(gender_arr[i], "male") == 0) vec.push_back(0);
        else vec.push_back(1);
    }
    sort(vec.begin(), vec.end(), greater<>());

    int ret = 0;
    for (int i = 0; i < gender_cnt; i++) {
        int multi = 1;
        int multi_cnt = gender_cnt - i - 1;
        while (multi_cnt) {
            multi *= 10;
            multi_cnt--;
        }
        ret += multi * vec[i];
    }
    return gender_match_info[ret];
}

void init() {
    mid_score_info.clear();
    for (int i = 1; i <= 21; i++) total_set[i].clear();
}

// O(logN)
int add(int mId, int mGrade, char mGender[7], int mScore) {
    int gender_num = strcmp(mGender, "male") == 0 ? 0 : 1;
    mid_score_info.insert({mId, {mScore, {mGrade, gender_num}}});
    vector<int> include_set_nums;
    for (auto it: grade_match_info) {
        int key = it.first;
        int grade_cnt = it.second;
        while (key) {
            if (key % 10 == mGrade) {
                if (gender_num) {
                    include_set_nums.push_back(grade_cnt * 3 + 2);
                } else {
                    include_set_nums.push_back(grade_cnt * 3 + 1);
                }
                include_set_nums.push_back(grade_cnt * 3 + 3);
                break;
            }
            key /= 10;
        }
    }

    for (int set_num: include_set_nums) {
        total_set[set_num].insert({mScore, mId});
    }

    int grade_set_num = grade_match_info[mGrade];
    int gender_set_num = gender_match_info[gender_num];
    int set_num = grade_set_num * 3 + gender_set_num;

    return total_set[set_num].rbegin()->second;
}

// o(logN)
int remove(int mId) {
    if (mid_score_info.find(mId) == mid_score_info.end()) return 0;
    piii mid_info = mid_score_info[mId];
    int score = mid_info.first;
    int grade = mid_info.second.first;
    int gender = mid_info.second.second;
    int set_num = grade_match_info[grade] * 3 + gender_match_info[gender];
    mid_score_info.erase(mId);
    for (int i = 1; i <= 21; i++) {
        if (total_set[i].find({score, mId}) != total_set[i].end()) {
            total_set[i].erase({score, mId});
        }
    }
    if(total_set[set_num].empty()) return 0;
    return total_set[set_num].begin()->second;
}

/*
 * mGrade {1,2,3} Grade 집합 {1}, {2}, {3}, {12}, {13}, {23}, {123}
 * mGener {male, female} 집합 {0}, {1}, {10}
 * 최악의 경우 6만번 실행가능 이때 학생은 2만명이 넘어갈 수 있음
 * 점수가 mScore 이상 학생중 가장 낮은 학생의 ID 출력
 * 특정 집합에 속해있는 데이터를 O(1) 에 가져와야함 총 18개의 집합
 * 해당 함수는 O(logN) 에 끝나야 함
 */
int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    int grade_set_num = get_grade_set_num(mGradeCnt, mGrade);
    int gender_set_num = get_gender_set_num(mGenderCnt, mGender);
    int set_num = grade_set_num * 3 + gender_set_num;

    auto find_info = total_set[set_num].lower_bound({mScore, -1});
    if (find_info == total_set[set_num].end()) return 0;
    return find_info->second;
}