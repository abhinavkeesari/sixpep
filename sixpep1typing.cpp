
//In the given code I have used file handling for permenant storage of the highest score because it have to be reloaded whenever application starts



#include <bits/stdc++.h>
#include<time.h>
#include<string>

using namespace std;
int high_score;
int main() {
    cout<<"Test your typing speed\n";
    int n1,total_s=0;
    do{
    	//given 10 different types of words
    const string words[10]={"sixpep", "varma", "mother", "parrot", "benten", "naruto", "rohith", "yamuna", "iphone", "adidas"};
     string word;
     time_t start;                 
     time_t end;                   
     int point=0,round_time;//round_time is time which is total time taken by the player to type a word in a single round
     cout<<"1. New Word 2. Score 3. HighScore 4. Save & Quit \n";
     int n;
     cin>>n;
     n1=n;
     string player_typed_word;//it stores the string typed by the player
     switch(n)
     {
         case 1:
         cout<<"player input is 1\n";
         word=words[rand()%10];  //selecting random word from the 10 words     
         cout<<"your new  word is "<<word<<". Type now \n";
         time(&start);
         cin>>player_typed_word;
         time(&end);
         round_time=end-start+1;  //calculationg time to type the word     
         cout<<"Time taken to type word is "<<round_time<<"seconds\n";
         //given points for different conditions
         if(player_typed_word!=word)
         point=-1;        
         else if(round_time<5)            
         point=2;
         else if(round_time<6)
         point=1;
         else if(round_time>6)
         point=0;
         total_s=point+total_s; //total score at end of every round
         cout<<"you scored "<<point<<" points and your total score is "<<total_s<<"\n";
         break;
         
         case 2:
         cout<<"player input is 2\n";
         cout<<total_s<<endl;
         break;
         
         case 3:
         	{
			 cout<<"player input is 3\n";
         int hscore;
         //checking whether the total_score of a player is greater than the previous highest score if yes changing the highest score and displaying it 
        if(total_s>high_score)
        {
        	ofstream oo("highscore.txt");
         	oo<<total_s;
         	oo.close();
		}   
		//reading the highest score stored from the file       
         ifstream obj("highscore.txt");
         if(obj>>hscore)
         cout<<hscore<<"\n";
         obj.close();
         break;
     }
         
         case 4:
         	{
			 cout<<"player input is 4\n";
			 cout<<"saving score and exiting the application\n";
			 //if total score of a player is greater changing the highest score 
         	ofstream oo("highscore.txt");
         	if(total_s>high_score)
         	oo<<total_s;
         	oo.close();
         	break;
         }
     }
         
         
     }while(n1!=4);//if case 4 ending the application
     
    
	return 0;
}
