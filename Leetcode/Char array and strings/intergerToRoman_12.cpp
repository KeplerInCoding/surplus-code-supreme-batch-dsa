// //medium
// class Solution {
// public:
//     string intToRoman(int num) {
//         map <int, char> mp;
//         mp[1]='I';
//         mp[5]='V';
//         mp[10]='X';
//         mp[50]='L';
//         mp[100]='C';
//         mp[500]='D';
//         mp[1000]='M';

//         string s;
//         int place = -1;

//         while(num){
//             place++;
//             int face = num%10;
//             num=num/10;

//             if(face==4){
//                 int index1 = 5*pow(10,place);
//                 int index2 = 1*pow(10,place);

//                 s.insert(0,1,mp[index1]);
//                 s.insert(0,1,mp[index2]);
//             }

//             else if(face==9){
//                 int index1 = pow(10,place+1);
//                 int index2 = pow(10,place);

//                 s.insert(0,1,mp[index1]);
//                 s.insert(0,1,mp[index2]);

//             }

//             else{
//                 int k = face%5;
                
//                 for(int i=0; i<k; i++){
//                     int index = pow(10,place);
//                     s.insert(0,1,mp[index]);
//                 }

//                 if(face/5){
//                     int index = 5*pow(10,place);
//                     s.insert(0,1,mp[index]);
//                 }
//             }

            

//         }
//         return s;
        
//     }
// };



class Solution {
public:
    string intToRoman(int num) {
        string s;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        for(int i=0; i<13; i++){
            while(num>=val[i]){
                s = s + sym[i];
                num = num - val[i];
            }
        }
        return s;
        
    }
};