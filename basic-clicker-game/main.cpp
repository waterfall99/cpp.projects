#include <raylib.h>
/*First Goal: Create a new window and download sprites to be placed in the window.
  Second Goal: Make the centre sprite clickable, add a counter in the top left
  to see your current click number
  Third Goal: Create upgrades that increase the number of clicks each click 
  will do
  Fourth Goal: Create a winning screen once click counter reaches a billion
  and stop all other activities
  Fifth Goal: Create a title screen and quit button
  First Goal: Complete
  Second Goal: Complete
  Third Goal: Complete
  Fourth Goal: Complete
  Fifth Goal: Complete*/ 
class Clicker_Game {
public:
    void run() {
        /* Initialising the window and all of the variables and clickable boxes*/
        InitWindow(1000, 600, "Button Clicker");
        SetTargetFPS(60);
        Texture2D buttonTex = LoadTexture("Red_Buttons_Pixel.png");
        long long Total_Clicks = 0;
        long long Clicks_Per_Click = 1;
        long long Upgrade1Cost = 15;
        Rectangle Upgrade1CostBox = {520.0f, 120.0f, 420.0f, 80.0f};
        long long Upgrade2Cost = 500;
        Rectangle Upgrade2CostBox = {520.0f, 230.0f, 420.0f, 80.0f};
        long long Upgrade3Cost = 5000;
        Rectangle Upgrade3CostBox = {520.0f, 340.0f, 420.0f, 80.0f};
        Rectangle buttonHitbox = {140.0f, 210.0f, 160.0f, 160.0f};
        int screenState = 0;
        bool shouldQuit = false;
        Rectangle playButton = {350.0f, 260.0f, 300.0f, 80.0f};
        Rectangle quitButton = {350.0f, 380.0f, 300.0f, 80.0f};
        while (!WindowShouldClose() && !shouldQuit) {
            if (screenState == 0) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
                    if (CheckCollisionPointRec(GetMousePosition(), playButton)) {
                        screenState = 1;
                    }
                    else if (CheckCollisionPointRec(GetMousePosition(), quitButton)) {
                        shouldQuit = true;
                    }
                }   
            }
            else if (screenState == 1) {
            /*This is checking if the player is pressing any of the boxes*/
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (CheckCollisionPointRec(GetMousePosition(), buttonHitbox)) {
                Total_Clicks += Clicks_Per_Click;
                }
                else if (CheckCollisionPointRec(GetMousePosition(), Upgrade1CostBox) 
                && Total_Clicks >= Upgrade1Cost) {
                    Total_Clicks -= Upgrade1Cost;
                    Clicks_Per_Click += 1;
                    Upgrade1Cost += 5;
                }
                else if (CheckCollisionPointRec(GetMousePosition(), Upgrade2CostBox) 
                && Total_Clicks >= Upgrade2Cost) {
                    Total_Clicks -= Upgrade2Cost;
                    Clicks_Per_Click += 100;
                    Upgrade2Cost += 500;
                }
                else if (CheckCollisionPointRec(GetMousePosition(), Upgrade3CostBox) 
                && Total_Clicks >= Upgrade3Cost) {
                    Total_Clicks -= Upgrade3Cost;
                    Clicks_Per_Click *= 2;
                    Upgrade3Cost *= 1.9;
                }
            } 
            if (Total_Clicks >= 1000000000LL) {
                screenState = 2;
            }
        }
            /*Creating the gameplay visuals*/
            BeginDrawing();
            ClearBackground(RAYWHITE);
            if (screenState == 0) {
                DrawText("Button Clicker", 350, 70, 50, BLACK);
                DrawRectangleRec(playButton, BLACK);
                DrawRectangleRec(quitButton, BLACK);
                DrawText("PLAY", 446, 280, 40, WHITE);
                DrawText("QUIT", 452, 400, 40, WHITE);
            }
            else if (screenState == 1) {
                DrawTextureEx(buttonTex, Vector2{150.0f, 220.0f}, 0.0f, 10.0f, WHITE);
                DrawText(TextFormat("Clicks: %lld", Total_Clicks), 20, 20, 30, BLACK);
                DrawText(TextFormat("Per Click: %lld", Clicks_Per_Click), 20, 55, 30, BLACK);
                DrawRectangleRec(Upgrade1CostBox, BLACK);
                DrawRectangleRec(Upgrade2CostBox, BLACK);
                DrawRectangleRec(Upgrade3CostBox, BLACK);
                DrawText("+1 Click / Click", 535, 132, 22, WHITE);
                DrawText(TextFormat("Cost: %lld", Upgrade1Cost), 535, 164, 22, WHITE);
                DrawText("+100 Click / Click", 535, 242, 22, WHITE);
                DrawText(TextFormat("Cost: %lld", Upgrade2Cost), 535, 274, 22, WHITE);
                DrawText("x2 Click / Click", 535, 352, 22, WHITE);
                DrawText(TextFormat("Cost: %lld", Upgrade3Cost), 535, 384, 22, WHITE);
            }   
            else if (screenState == 2) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
                    if (CheckCollisionPointRec(GetMousePosition(), playButton)) {
                        Total_Clicks = 0;
                        Clicks_Per_Click = 1;
                        Upgrade1Cost = 15;
                        Upgrade2Cost = 500;
                        Upgrade3Cost = 5000;
                        screenState = 1;
                    }
                    else if (CheckCollisionPointRec(GetMousePosition(), quitButton)) {
                        shouldQuit = true;
                    }
                }
                DrawText("YOU WIN!!!", 310, 90, 80, DARKGREEN);
                DrawText("You reached 1,000,000,000 clicks!", 255, 190, 30, DARKGRAY);
                DrawRectangleRec(playButton, BLACK);
                DrawRectangleRec(quitButton, BLACK);
                DrawText("PLAY AGAIN", 390, 282, 36, WHITE);
                DrawText("QUIT", 452, 400, 40, WHITE);
            }
        EndDrawing();
        }   
        UnloadTexture(buttonTex);
        CloseWindow();
};
};
int main() {
Clicker_Game game;
game.run();


return 0;
}
