# memory-appa-game
So my plan originally was to make a reaction time game but later when I started doing my firmware I thought that doing a memory game would be more fun. So my plan was to create an appa pcb layout for my game since I wanted to incorporate some of the stuff that I like into my projects. 
Step 1: I started working on creating the PCB I only wanted 3 buttons and 3 leds so I did just that and wired my resistors too (to the leds) . I also added the microcontroller as seen below. 
<img width="461" height="483" alt="Screenshot 2026-10-30 185535" src="https://github.com/user-attachments/assets/caf9b2e0-bd5f-46a4-bc6f-dbec52ca6619" />
Actually originally I didn't think of the appa idea and wanted to create something simple as seen below but then I changed it because as said before, I wanted something that represented what I liked. (the picture below was my original design)
<img width="394" height="397" alt="Screenshot 2026-10-30 192357" src="https://github.com/user-attachments/assets/a4cfebc7-a343-4192-ae8b-41701c8dab42" />
Step 2: I redesigned the edge.cuts layer for my pcb the first time I made it I made appa too small :_( so my components didn't fit inside appa which was annoying so I made appa wider and fit my components in as seen below. 
Step 3: I routed everything up and this time it was fairly simple only took me 30 minutes-1 hour to do (still haven't mastered it) this time I didn't have to use any vias (vias connect the front red lines with the back blue layer lines) which I was proud of. 
<img width="215" height="373" alt="Screenshot 2026-10-30 195630" src="https://github.com/user-attachments/assets/f4551d1a-2e23-43d4-8335-521e9eab4cfd" />
<img width="837" height="564" alt="Screenshot 2026-10-30 200524" src="https://github.com/user-attachments/assets/25ffbfcb-f099-4438-9361-123ab3884fcf" />
Step 4:Designing time! My favorite part! I converted my images of appas arrows using the image converter tool on kicad and had to figure out how to move it to back silkscreen which took some time but I later figured it out. I also had to painstakingly use the custom line screenshot tool to go over his back arrows. Then I checked the 3D models and it looked pretty good! (2nd and 3rd pics) 
<img width="255" height="494" alt="Screenshot 2026-10-30 225653" src="https://github.com/user-attachments/assets/44b99e0e-85d4-4b66-9e24-5807310c5a6d" />
Before: <img width="387" height="626" alt="Screenshot 2026-10-30 225716" src="https://github.com/user-attachments/assets/b14c38cd-3a30-4e8c-b73d-3de7cd72230f" />
After: <img width="297" height="615" alt="Screenshot 2026-10-30 225743" src="https://github.com/user-attachments/assets/1f2e22e9-8da4-4f87-9ea2-693460e528d7" />
Step 5: Adding 3d models! It took me some time to find the folders to the 3d models but I figured it out and rotated the models to fit the lines. 
Front: <img width="268" height="633" alt="Screenshot 2026-10-30 234713" src="https://github.com/user-attachments/assets/f4f8e1df-0e29-43c6-b0ab-76cb59e86128" />
Back: <img width="297" height="615" alt="Screenshot 2026-10-30 234740" src="https://github.com/user-attachments/assets/0e27f414-998d-4fcf-b4bf-5a04787527d9" />
Step 6: Firmware. Coded this on arduino IDE. The comments inserted basically explain most parts of the code. The max level is 50, if you get the sequence wrong you start from level 0, long pressing button 1 for 1 second starts the game, if you long press button 1 for 2 seconds it quits the game. If you win the game basically level 50 all leds shine.
<img width="355" height="507" alt="Screenshot 2026-10-31 151446" src="https://github.com/user-attachments/assets/7cad1ccb-82fd-4b24-ab7f-e98bc3f72892" />
<img width="887" height="544" alt="Screenshot 2026-11-01 152712" src="https://github.com/user-attachments/assets/18181cb2-705e-499a-a20e-17f30b683b01" />
<img width="798" height="531" alt="Screenshot 2026-11-01 152727" src="https://github.com/user-attachments/assets/386868c9-bc0f-4568-855b-8020660f6fb9" />
<img width="1013" height="548" alt="Screenshot 2026-11-01 152745" src="https://github.com/user-attachments/assets/552dc91d-cf5f-421a-a38a-9c943f3ce8ee" />
<img width="994" height="526" alt="Screenshot 2026-11-01 152757" src="https://github.com/user-attachments/assets/1f8c42d8-9a54-45cc-ab94-d3b568cb2d75" />
<img width="851" height="525" alt="Screenshot 2026-11-01 152810" src="https://github.com/user-attachments/assets/53d7f97d-d415-4bdc-9fec-b682a4fcbfe8" />
**Bonus** Something I did for fun as a break from the firmware is make a 3d model for aang but I might just print it out myself. I built it on onshape and I just used a rectangular prism and a sphere. I might make more of the gang later.
How it actually looks: <img width="263" height="362" alt="Screenshot 2026-10-31 155901" src="https://github.com/user-attachments/assets/f638580d-4acf-4f59-9188-9fc68ca1c53c" />
What I want to design on: <img width="263" height="362" alt="Screenshot 2026-10-31 dd155901" src="https://github.com/user-attachments/assets/6bb02e85-9d75-4db7-adec-dc77dc464c30" />


