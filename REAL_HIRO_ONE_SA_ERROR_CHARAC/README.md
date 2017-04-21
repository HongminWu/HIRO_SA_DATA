Data from snap assembly work with the HIRO Robot. 
Dates: 2016.

Trials:     17
Arm:        Right arm. 
Experiment: HIRO's right arm holds a male camera part with 4 snaps. Female part is rigidly fixed to the table in front of robot. Hiro tries to do a snap assembly but fails. The experiment starts with a guarded approach to the female part until both parts make contact at an angle (angle of approach is 22.5 degrees about the y-axis (pitch) to the horizontal). A rotational motion does a near-full alignment until the back-side snaps make contact. Then an insertion takes place, along with a large snap or impact. Then, parts remain mated till the end of the xperiment.

Each folder contains the following files and data:
i. R_Angles.dat (7DoF Actual Joint Angles)
Format: time-stamp theta1 ...  theta7

ii. R_CartPos.dat (xyzrpy end-effect Cartesian positions)
Format: time-stap x y z r p y

iii. R_Torques.dat (Actual Wrench data wrt end-effector)
Format: time Fx Fy Fz Mx My Mz

iv. R_State.dat (Time stamps of state transitions)
Format: time (secs)

v. worldforce.dat (Actual Wrench data wrt world)
Format: time Fx Fy Fz Mx My Mz

vi. pivotApproachState2 (2 waypoints that guide an interpolated trajectory):
Format: time (secs) x y z r p y
