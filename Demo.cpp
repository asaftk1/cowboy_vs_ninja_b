/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;

#include "sources/Team.hpp"      //no need for other includes
#include "sources/SmartTeam.hpp" //no need for other includes

using namespace ariel;
// Function to generate a random point
// double generateRandomPoint(double min, double max)
// {
//    static std::mt19937 mt(static_cast<unsigned long>(std::time(nullptr)));
//    std::uniform_real_distribution<double> dist(min, max);
//    return dist(mt);
// }
// auto create_yninja = [](double x = random_float(), double y = random_float())
// {
//    return new YoungNinja{"YoungNinja", Point{x, y}};
// };

// auto create_tninja = [](double x = random_float(), double y = random_float())
// {
//    return new TrainedNinja{"TraindNinja", Point{x, y}};
// };

// auto create_oninja = [](double x = random_float(), double y = random_float())
// {
//    return new OldNinja{"Oldninja", Point{x, y}};
// };

// auto create_cowboy = [](double x = random_float(), double y = random_float())
// {
//    return new Cowboy{"Cowboy", Point{x, y}};
// };

// double random_float(double min = -100, double max = 100)

// {
//    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
//    std::uniform_real_distribution<double> distribution(min, max);

//    return distribution(generator);
// }


int main()
{
   Point a(32.3, 44), b(1.3, 3.5);
   assert(a.distance(b) == b.distance(a));
   Cowboy *tom = new Cowboy("Tom", a);
   OldNinja *sushi = new OldNinja("sushi", b);
   tom->shoot(sushi);
   cout << tom->print() << endl;

   sushi->move(tom);
   sushi->slash(tom);

    Team team_A(tom);
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

   // Team b(tom); should throw tom is already in team a

   Team team_B(sushi);
   team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

   // SmartTeam team_C(tom);
   // team_C.add(new YoungNinja("Yogi", Point(64, 57)));

   while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
   {

      team_A.attack(&team_B);
      team_B.attack(&team_A);
      team_A.print();
      team_B.print();
   }

   if (team_A.stillAlive() > 0)
      cout << "winner is team_A" << endl;
   else
      cout << "winner is team_B" << endl;

   // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.
   //////////////////////////////////MyDemo///////////////////////////////

   ////initializations////////
//    auto Youngninja = create_yninja();
//    auto Oldninja = create_oninja();
//    auto Traindninja = create_tninja();
//    auto Cowboy = create_cowboy();

//    //////////// HitPoints After initialization ///////////////
//    (Youngninja->getHitPoints() == 100) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 100" << endl;
//    (Oldninja->getHitPoints() == 150) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 150" << endl;
//    (Traindninja->getHitPoints() == 120) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 120" << endl;
//    (Cowboy->getHitPoints() == 110) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 110" << endl;

//    /////////// Ninja Speed and cowboy bulets after initialization///////////
//    (Youngninja->getSpeed() == 14) ? cout << "correct" << endl : cout << "incorrect, speed != 14" << endl;
//    (Oldninja->getSpeed() == 8) ? cout << "correct" << endl : cout << "incorrect, speed != 8" << endl;
//    (Traindninja->getSpeed() == 12) ? cout << "correct" << endl : cout << "incorrect, speed != 12" << endl;
//    (Cowboy->getbullets() == 6) ? cout << "correct" << endl : cout << "incorrect, bulets !=6" << endl;

//    /// Shoot Check////
//    Cowboy->shoot(Oldninja);
//    Cowboy->shoot(Youngninja);
//    Cowboy->shoot(Traindninja);
//    (Youngninja->getHitPoints() == 90) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 90" << endl;
//    (Oldninja->getHitPoints() == 140) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 140" << endl;
//    (Traindninja->getHitPoints() == 110) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 110" << endl;

//    ////Slash Check////
//    while (Youngninja->distance(Oldninja) > 1.0)
//    {
//       Youngninja->move(Oldninja);
//    }
//    Youngninja->slash(Oldninja);
//    (Oldninja->getHitPoints() == 100) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 100" << endl;
//    Oldninja->slash(Youngninja);
//    (Youngninja->getHitPoints() == 50) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 90" << endl;
//    /// isAlive Check////
//    (Youngninja->isAlive()) ? cout << "correct" << endl : cout << "incorrect, HitPoints != 90" << endl;
//    Cowboy->shoot(Youngninja);
//    Oldninja->slash(Youngninja);
//    (!Youngninja->isAlive()) ? cout << "correct" << endl : cout << "incorrect, Youngninja lives" << endl;

//    /// bulets && reload Check///
//    (Cowboy->getbullets() == 2) ? cout << "correct" << endl : cout << "incorrect, bulets !=2" << endl;
//    Cowboy->reload();
//    (Cowboy->getbullets() == 6) ? cout << "correct" << endl : cout << "incorrect, bulets !=6" << endl;

//    // move Check ///
//    double distance1 = Oldninja->distance(Traindninja);
//    Oldninja->move(Traindninja);
//    double distance2 = Oldninja->distance(Traindninja);

//    (distance1 > distance2) ? cout << "correct" << endl : cout << "incorrect, move function is wrong" << endl;

//    // Team ////
//    auto Yn = create_yninja();
//    auto On = create_oninja();
//    auto Tn = create_tninja();
//    auto Cb = create_cowboy();
//    Team team1(Yn);
//    Team team2(On);
//    team1.add(Tn);
//    team2.add(Cb);

//    (team1.stillAlive() == 2 && team2.stillAlive() == 2) ? cout << "correct" << endl : cout << "incorrect, move function is wrong" << endl;

//    team1.print();
//    team2.print(); /// cowboy should be printed first

//    while (team1.stillAlive() > 0 && team2.stillAlive() > 0)
//    {
//       team1.attack(&team2);
//       // if(team2.stillAlive() > 0){
//       team2.attack(&team1); //}
//    }
//    team1.print(); /// sohuld be printed as asked in the ex
//    team2.print(); /// cowboy should be printed first with (c) at the beggining and without hitpoints if he is dead
//    cout << "///////////////////////////" << endl;
//    // Team2 team3(Yn);// sohuld throw exeption

//    // full team battle ////
//    auto Yn2 = create_yninja();
//    auto On2 = create_oninja();
//    auto Tn2 = create_tninja();
//    auto Cb2 = create_cowboy();
//    auto Yn3 = create_yninja();
//    auto On3 = create_oninja();
//    auto Tn3 = create_tninja();
//    auto Cb3 = create_cowboy();
//    auto Yn4 = create_yninja();
//    auto On4 = create_oninja();
//    auto Tn4 = create_tninja();
//    auto Cb4 = create_cowboy();

//    Team team5(Yn2);
//    Team team6(On2);
//    Team team7(Tn2);
//    Team team8(Cb2);
//    Team2 team9(Yn3);
//    Team2 team10(Tn3);
//    Team2 team11(On3);
//    Team2 team12(Cb3);
//    SmartTeam smartTeam1(Yn4);
//    SmartTeam smartTeam2(On4);
//    SmartTeam smartTeam3(Tn4);
//    SmartTeam smartTeam4(Cb4);

//    for (int i = 1; i <= 5; ++i)
//    {

//       team5.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team6.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team7.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team8.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team9.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team10.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team11.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team12.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       smartTeam1.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       smartTeam2.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       smartTeam3.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       smartTeam4.add(create_cowboy(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//    }
//    for (int i = 1; i < 5; ++i)
//    {
//       team5.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team6.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team7.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team8.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team9.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team10.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team11.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       team12.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       smartTeam1.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       smartTeam2.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       smartTeam3.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//       smartTeam4.add(create_yninja(generateRandomPoint(1.0, 100.0), generateRandomPoint(1.0, 100.0)));
//    }
//    ////////////////////////team vs team///////////////////////////////
//    while (team5.stillAlive() > 0 && team6.stillAlive() > 0)
//    {
//       team5.attack(&team6);
//       // if(team6.stillAlive()>0){
//       team6.attack(&team5); //}
//    }
//    team5.print();
//    team6.print();
//    cout << "///////////////////////////" << endl;

//    if (team5.stillAlive() > 0)
//       cout << "winner is team_5" << endl;
//    else
//       cout << "winner is team_6" << endl;
//          cout << "///////////////////////////" << endl;

//    ///////////////////////////////////team vs team2///////////////////////////
//    while (team7.stillAlive() > 0 && team9.stillAlive() > 0)
//    {
//       team7.attack(&team9);
//       // if(team6.stillAlive()>0){
//       team9.attack(&team7); //}
//    }
//    team7.print();
//    team9.print();

//    if (team7.stillAlive() > 0)
//       cout << "winner is team_7" << endl;
//    else
//       cout << "winner is team_9" << endl;
//    cout << "///////////////////////////" << endl;

//    /////////////////////////////////team vs smart team/////////////////////////
//    while (team8.stillAlive() > 0 && smartTeam1.stillAlive() > 0)
//    {
//       team8.attack(&smartTeam1);
//       // if(team6.stillAlive()>0){
//       smartTeam1.attack(&team8); //}
//    }
//    team8.print();
//    smartTeam1.print();

//    if (team8.stillAlive() > 0)
//       cout << "winner is team_8" << endl;
//    else
//       cout << "winner is smartTeam1" << endl;
//    cout << "///////////////////////////" << endl;

//    ///////////////////////team 2 vs team2///////////////////////////////
//    while (team10.stillAlive() > 0 && team11.stillAlive() > 0)
//    {
//       team10.attack(&team11);
//       // if(team6.stillAlive()>0){
//       team11.attack(&team10); //}
//    }
//    team10.print();
//    team11.print();

//    if (team10.stillAlive() > 0)
//       cout << "winner is team_10" << endl;
//    else
//       cout << "winner is team_11" << endl;
//    cout << "///////////////////////////" << endl;
//    ///////////////////////team 2 vs smart team///////////////////////////////
//    while (team12.stillAlive() > 0 && smartTeam2.stillAlive() > 0)
//    {
//       team12.attack(&smartTeam2);
//       // if(team6.stillAlive()>0){
//       smartTeam2.attack(&team12); //}
//    }
//    team12.print();
//    smartTeam2.print();

//    if (team12.stillAlive() > 0)
//       cout << "winner is team_12" << endl;
//    else
//       cout << "winner is smartTeam2" << endl;
//    cout << "///////////////////////////" << endl;
//    ///////////////////////smart team  vs smart team///////////////////////////////
// while (smartTeam3.stillAlive() > 0 && smartTeam4.stillAlive() > 0)
//    {
//       smartTeam3.attack(&smartTeam4);
//       // if(team6.stillAlive()>0){
//       smartTeam4.attack(&smartTeam3); //}
//    }
//    smartTeam3.print();
//    smartTeam4.print();

//    if (smartTeam3.stillAlive() > 0)
//       cout << "winner is smartTeam3" << endl;
//    else
//       cout << "winner is smartTeam4" << endl;
//    cout << "///////////////////////////" << endl;
   return 0;
}
