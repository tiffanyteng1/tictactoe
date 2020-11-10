//
//  main.cpp
//  a3_q1
//
//  Created by Tiffany Teng on 2020-10-30.
//  Copyright © 2020 Tiffany Teng. All rights reserved.
//

#include <iostream>
using namespace std;


// I tested this program by running it a multitude of times ensuring that each event could occur and that stats were being counted correctly. Also, by outputting the generated number, i ensured that the correct values were being assigned to the correct event
    // I looked to make sure for each function all of the different outcomes were possible
        // Testing:
                // 20 events possible
                // shot_outcomes -- was able to generate all the outcomes
                // get_foul_card -- was able to generate all the outcome
                // soccer_simulation -- gives correct output for event number
                // to ensure stats were correct, I outputted the stats after each event to ensure that the outcome was being counted in the correct spot before changing it back to only halfway through the game and at the end
// limitations -- it doesn't truly stimulate a real soccer game as there is no time delay in events, also all the odds are the same for both team. In reality, there is often a team that could be better than the other, where skill comes into play, and the events decided aren't by the 'roll of a dice'.



// Step 0. initialize and declare variables
// Team A and B counters -- score, fouls, number of shots
//Step 1. make function soccer_simulation -- generate random numbers[1,20] for number of events
//step 2. for each event ( iterate through ) generate from [1,6] for each event
    // step 2.1 use booleans for shot and set to true ( 1 = team A shot, 2 = team B shot)
        // step 2.10 make function shot_outcome
            //if true, generate [0,3] - ( 0 = goal , 1 = goalkeeper/defender saved, 2 = shot was off goal, 3 = shot was blocked by other player)
            // store outputs in counters
        // step 2.11 outout results
    //step 2.2 set booleans for true for foul if get 3 or 4( 3 = team B foul( Team A free kick) 4 = team A foul (Team B free kick))
        // step 2.20 use function shot_outcome
        // step 2.21 make function foul_card
            //generate [0,2] to give no card, yellowcard or red card respectively -- add to counter
        // step 2.22 output results
    //step 2.3 set booleans for foul close to goal and penalty kick if value is 5 or 6
        // step 2.30 use function shot_outcome
        // step 2.31 use function foul_card
        // step 2.32 output results
// step 3. after 10 events, print game stats ( current score, shots on goal, shots off goal, blocket shots, fouls, yellow cards, and red cards )



void shot_outcome(bool &has_scored, bool &shot_on_goal,
                  bool &shot_off_goal, bool &player_blocked_shot) // each time a shot is taken, gives the output if the shot is scored, missed, or blocked
{
    //initialize the value of the outcome that will represent the outcome (0-3 options)
    int outcome_value = 0 ;
    outcome_value = rand() % 4;
   
    
    if (outcome_value == 0){ // if 0, the team has scored
        has_scored = true;
    }
    else if (outcome_value == 1){ // if 1, the team has a shot on goal, but the defense or goalie saved it
        shot_on_goal = true;
    }
    else if (outcome_value == 2){ // if 2, the team missed the shot
        shot_off_goal = true;
    }
    else { // if 3, another player blocks the shot
        player_blocked_shot = true;
    }
    
}

void get_foul_card(bool &no_foul_card, bool &yellow_card_given,
                   bool &red_card_given) // each time a foul occurs, it decides if a the team will either get no card, a yellow card or a red card
{
    // initializes the randomly generated value that will represent the outcome (0-2 options)
    int foul_value = 0;
    foul_value = rand() % 3;
    
    
    if (foul_value == 0){
        no_foul_card = true; // if 0, the team does not recieve a foul card
    }
    else if (foul_value == 1){
        yellow_card_given = true; // if 1, the team receives a yellow card
    }
    else if (foul_value == 2){
        red_card_given = true; // if 2, the team receives a red card
    }
    
}

void update_stats_team_a(bool has_scored, bool shot_on_goal,
                         bool shot_off_goal, bool player_blocked_shot,
                         bool no_foul_card, bool yellow_card_given,
                         bool red_card_given, int &team_a_goals,
                         int &team_a_shot_blocked_goalie, int &team_a_shots_off,
                         int &team_a_blocked_shots, int &team_b_yellow_cards,
                         int &team_b_red_cards, int &team_b_no_foul) // updates the stats for team a and the fouls for team b, and outputs a message to the user
{

        // increase counters for each each and give corresponding output
    if (has_scored){
        
        team_a_goals++;
        cout << "   Team A has scored! Amazing shot!" << endl << endl;
        
    }
    else if (shot_on_goal){
        
        team_a_shot_blocked_goalie++;
        cout << "   The goalie saves it! What a good save!" <<endl<<endl;
    }
    else if (shot_off_goal){
        
        team_a_shots_off++;
        cout << "   Team A misses!" << endl <<endl;
        
    }
    else if (player_blocked_shot){
       
        team_a_blocked_shots++;
        cout << "   It is saved by another player!" << endl <<endl;
    }
    
    
    if (yellow_card_given){ // takes information for fouls for team b
         
        team_b_yellow_cards++;
        cout << " Team B gets a yellow card!" << endl <<endl;
     }
     else if (red_card_given){
         
         team_b_red_cards++;
         cout << " Team B gets a red card!" <<endl <<endl;
         
     }
     else if(no_foul_card){
         
         team_b_no_foul++;
         cout << " No yellow or red card for Team B! "<< endl <<endl;
     }
    
      
    
    
}

void update_stats_team_b(bool has_scored, bool shot_on_goal,
                         bool shot_off_goal, bool player_blocked_shot,
                         bool no_foul_card, bool yellow_card_given,
                         bool red_card_given, int &team_b_goals,
                         int &team_b_shots_blocked_goalie, int &team_b_shots_off,
                         int &team_b_blocked_shots, int &team_a_yellow_cards,
                         int &team_a_red_cards, int &team_a_no_foul) // updates stats for team b and fouls for team a, and outputs the outcomes to the user
{
    

    if (has_scored){ // increase counters for each event
        
        team_b_goals++;
        cout << "   Team B has scored! Amazing shot!" << endl<<endl;
        
       }
    else if (shot_on_goal){
        
        team_b_shots_blocked_goalie++;
        cout << "   The goalie saves it! What a good save!" <<endl<<endl;
        
       }
    else if (shot_off_goal){
        
        team_b_shots_off++;
        cout << "   Team B misses!" << endl<<endl;
        
       }
    else if (player_blocked_shot){
        
        team_b_blocked_shots++;
        cout << "   It is saved by another player! " << endl<<endl;
        
       }
    
    if (yellow_card_given){ // collects foul data for team a
      
        team_a_yellow_cards++;
        cout << " Team A gets a yellow card!" << endl<<endl;
        
    }
    else if (red_card_given){
       
        team_a_red_cards++;
        cout << " Team A gets a red card!" <<endl<<endl;
    }
    else if(no_foul_card){
        
        team_a_no_foul++;
        cout << " No yellow or red card for Team A! "<< endl<<endl;
        
    }
       
    
    
}
void output_stats(int team_b_goals, int team_b_shots_blocked_goalie,
                  int team_b_shots_off, int team_b_blocked_shots,
                  int team_b_yellow_cards, int team_b_red_cards,
                  int team_b_no_foul, int team_a_goals,
                  int team_a_shot_blocked_goalie, int team_a_shots_off,
                  int team_a_blocked_shots, int team_a_yellow_cards,
                  int team_a_red_cards, int team_a_no_foul){ // outputs the total stats for each team
 
    
    cout << "Team A stats: \n   Number of goals: "<< team_a_goals // outputs all of team a stats
        << "\n   Number of shots on goal: "<< (team_a_goals + team_a_blocked_shots + team_a_shot_blocked_goalie) // total shots includes the goals and those blocked by other players
        << "\n   Number of shots off goal: " << team_a_shots_off
        << "\n   Number of blocked shots: " << (team_a_blocked_shots + team_a_shot_blocked_goalie) // number of blocked shots are by goalie, defenders and other players
        << "\n   Number of fouls: " <<(team_a_red_cards + team_a_yellow_cards + team_a_no_foul) // // total fouls are given by the red card, yellow cards and no fouls
        << "\n   Yellow cards: " << team_a_yellow_cards
        << "\n   Red Cards: "<< team_a_red_cards << endl<< endl;
    
     
    cout << "Team B stats: \n   Number of goals: "<< team_b_goals // outputs all of team b stats
        << " \n   Number of shots on goal: "<< (team_b_goals + team_b_blocked_shots + team_b_shots_blocked_goalie)
        << "\n   Number of shots off goal: " << team_b_shots_off
        << "\n   Number of blocked shots: " << (team_b_blocked_shots + team_b_shots_blocked_goalie)
        << "\n   Number of fouls: " << (team_b_no_foul + team_b_red_cards + team_b_yellow_cards)
        << "\n   Yellow cards: " << team_b_yellow_cards
        << "\n   Red Cards: "<< team_b_red_cards << endl<< endl;

}

void soccer_simulation(){
    // [PURPOSE]: stimulate a soccer game: generate random values to represent scored, saved, fouls, free kicks, penalty kicks and corresponding statements in a game
        // divide the game in 2 and print out stats halfway

    //[INPUT] : srand() - randomly generated values for events
    //[PROCESSING]: assign random values to a represented events
    //[OUTPUT]: the corresponding statments of events that occurred and scores halfway and at the end
    
    //initialize anf declare all the variables
    int number_of_events = 0;
    int event = 0;
    
    //goals, shots, blocks variables
    bool has_scored = false;
    bool shot_on_goal = false;
    bool shot_off_goal = false;
    bool player_blocked_shot = false;
    
    //foul card booleans
    bool no_foul_card = false;
    bool yellow_card_given = false;
    bool red_card_given = false;
    
    //team a counters
    int team_a_goals = 0;
    int team_a_shot_blocked_goalie = 0;
    int team_a_shots_off = 0;
    int team_a_blocked_shots = 0;
    int team_a_yellow_cards = 0;
    int team_a_red_cards = 0;
    int team_a_no_foul = 0;
    
    //team b counters
    int team_b_goals = 0;
    int team_b_shots_off = 0;
    int team_b_blocked_shots = 0;
    int team_b_shots_blocked_goalie = 0;
    int team_b_yellow_cards = 0;
    int team_b_red_cards = 0;
    int team_b_no_foul = 0;
    
    
    
    number_of_events = rand() % 20 + 1 ; // generates a random numner from 1 - 20 for the number of eventrs
    
    for (int index = 1 ; index < number_of_events + 1; index++) {
        
        event = rand() % 6 + 1; // for each event, generates 6 random numbers
       
        cout << "Event #" << index << endl;
       
        if ( event == 1){ // team a has a shot
            
            cout << "Team A takes a shot...... and....." <<endl;
            
            shot_outcome(has_scored, shot_on_goal, shot_off_goal, player_blocked_shot); // determine if the shot went in
            update_stats_team_a(has_scored, shot_on_goal, // update the stats
                                shot_off_goal, player_blocked_shot,
                                no_foul_card, yellow_card_given,
                                red_card_given, team_a_goals,
                                team_a_shot_blocked_goalie, team_a_shots_off,
                                team_a_blocked_shots, team_a_yellow_cards,
                                team_a_red_cards, team_a_no_foul);
            
         
        }
        else if ( event == 2 ){ // team b has a shot
           
            cout << "Team B takes a shot...... and....." <<endl;
            
            shot_outcome(has_scored, shot_on_goal, shot_off_goal, player_blocked_shot);
            update_stats_team_b(has_scored, shot_on_goal,
                                shot_off_goal, player_blocked_shot,
                                no_foul_card, yellow_card_given,
                                red_card_given, team_b_goals,
                                team_b_shots_blocked_goalie, team_b_shots_off,
                                team_b_blocked_shots, team_a_yellow_cards,
                                team_a_red_cards, team_a_no_foul);

        }
        else if ( event == 3 ){ // team b has a foul, and team a has a free kick
            
            cout << " Foul on Team B, Team A has a free kick" << "\n" << "Team A takes a shot...... and....." << endl;
            
            shot_outcome(has_scored, shot_on_goal, shot_off_goal, player_blocked_shot);
            get_foul_card(no_foul_card, yellow_card_given, red_card_given); // determine if a card is given
            update_stats_team_a(has_scored, shot_on_goal,
                                shot_off_goal, player_blocked_shot,
                                no_foul_card, yellow_card_given,
                                red_card_given, team_a_goals,
                                team_a_shot_blocked_goalie, team_a_shots_off,
                                team_a_blocked_shots, team_b_yellow_cards,
                                team_b_red_cards, team_b_no_foul);
          
        }
        else if ( event == 4 ){  //team a has foul and team b has a free kick
            
            cout << " Foul on Team A, Team B has a free kick" << "\n" << "Team B takes a shot...... and....." << endl;
            
            shot_outcome(has_scored, shot_on_goal, shot_off_goal, player_blocked_shot);
            get_foul_card(no_foul_card, yellow_card_given, red_card_given);
            update_stats_team_b(has_scored, shot_on_goal,
                                shot_off_goal,player_blocked_shot,
                                no_foul_card, yellow_card_given,
                                red_card_given, team_b_goals,
                                team_b_shots_blocked_goalie, team_b_shots_off,
                                team_b_blocked_shots, team_a_yellow_cards,
                                team_a_red_cards, team_a_no_foul);
           
        }
        else if ( event == 5 ){ //team b has foul close to the net , team a has penalty kick
            
            cout << "Foul on Team B, Team A has a penalty kick." << "\n" <<"Team A takes a shot...... and..... " << endl;
            
            get_foul_card(no_foul_card, yellow_card_given, red_card_given);
            shot_outcome(has_scored, shot_on_goal, shot_off_goal, player_blocked_shot);
            update_stats_team_a(has_scored, shot_on_goal,
                                shot_off_goal, player_blocked_shot,
                                no_foul_card, yellow_card_given,
                                red_card_given, team_a_goals,
                                team_a_shot_blocked_goalie, team_a_shots_off,
                                team_a_blocked_shots, team_b_yellow_cards,
                                team_b_red_cards, team_b_no_foul);
            
        }
        else {  //team a has foul close to the net, team b has penalty kick
           
            cout << "Foul on Team A, Team B has a penalty kick." << "\n" <<"Team B takes a shot...... and..... " << endl;
            
            get_foul_card(no_foul_card, yellow_card_given, red_card_given);
            shot_outcome(has_scored, shot_on_goal, shot_off_goal, player_blocked_shot);
            update_stats_team_b(has_scored, shot_on_goal,
                                shot_off_goal, player_blocked_shot,
                                no_foul_card, yellow_card_given,
                                red_card_given, team_b_goals,
                                team_b_shots_blocked_goalie, team_b_shots_off,
                                team_b_blocked_shots, team_a_yellow_cards,
                                team_a_red_cards, team_a_no_foul);
           
        }
        
       
        if (index == number_of_events/2 || index == number_of_events ){ // output stats halfway through the game and at the end
                  output_stats( team_b_goals, team_b_shots_blocked_goalie,
                               team_b_shots_off, team_b_blocked_shots,
                               team_b_yellow_cards, team_b_red_cards,
                               team_b_no_foul, team_a_goals,
                               team_a_shot_blocked_goalie, team_a_shots_off,
                               team_a_blocked_shots, team_a_yellow_cards,
                               team_a_red_cards, team_a_no_foul);
        }
        
    }
}


int main() {
    
    srand((unsigned) (time(0))); // generates different random values
    soccer_simulation();
    
}
