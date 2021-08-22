# darpa_virtual_model_submit
Simulation model for the Kolibri Mapping OMAV submitted to the DARPA SubT Challenge for team CERBERUS. 

## workspace setup
Follow these step to setup the DARPA Subt Virtual Environment: 

https://github.com/osrf/subt/wiki/Catkin%20System%20Setup

Needs to be slightly adjusted for 20.04.

## launch the simulation
ign launch -v 4 competition.ign circuit:=tunnel worldName:=tunnel_circuit_practice_01 robotName1:=kolibri robotConfig1:=CERBERUS_KOLIBRI_SENSOR_CONFIG_1 localModel:=true 


