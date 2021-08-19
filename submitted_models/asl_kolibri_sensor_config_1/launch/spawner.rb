def spawner(_name, _modelURI, _worldName, _x, _y, _z, _roll, _pitch, _yaw)
  <<-HEREDOC
  <spawn name='#{_name}'>
      <name>#{_name}</name>
      <allow_renaming>false</allow_renaming>
      <pose>#{_x} #{_y} #{_z + 0.2} #{_roll} #{_pitch} #{_yaw}</pose>
      <world>#{_worldName}</world>
      <is_performer>true</is_performer>
      <sdf version='1.6'>
      <include>
      <name>#{_name}</name>
      <uri>#{_modelURI}</uri>
      <!-- Publish robot state information -->
      <plugin filename="libignition-gazebo-pose-publisher-system.so"
        name="ignition::gazebo::systems::PosePublisher">
        <publish_link_pose>true</publish_link_pose>
        <publish_sensor_pose>true</publish_sensor_pose>
        <publish_collision_pose>false</publish_collision_pose>
        <publish_visual_pose>false</publish_visual_pose>
        <publish_nested_model_pose>#{$enableGroundTruth}</publish_nested_model_pose>
        <use_pose_vector_msg>true</use_pose_vector_msg>
        <static_publisher>true</static_publisher>
        <static_update_frequency>1</static_update_frequency>
      </plugin>
      <!-- Battery plugin -->
      <plugin filename="libignition-gazebo-linearbatteryplugin-system.so"
        name="ignition::gazebo::systems::LinearBatteryPlugin">
        <battery_name>linear_battery</battery_name>
        <voltage>12.694</voltage>
        <open_circuit_voltage_constant_coef>12.694</open_circuit_voltage_constant_coef>
        <open_circuit_voltage_linear_coef>-3.1424</open_circuit_voltage_linear_coef>
        <initial_charge>18.0</initial_charge>
        <capacity>18.0</capacity>
        <resistance>0.061523</resistance>
        <smooth_current_tau>1.9499</smooth_current_tau>
        <power_load>6.6</power_load>
        <start_on_motion>true</start_on_motion>
      </plugin>
      <!-- Gas Sensor plugin -->
      <plugin filename="libGasEmitterDetectorPlugin.so"
        name="subt::GasDetector">
        <topic>/model/#{_name}/gas_detected</topic>
        <update_rate>10</update_rate>
        <type>gas</type>
      </plugin>
    </include>
    </sdf>
  </spawn>
  HEREDOC
end

def rosExecutables(_name, _worldName)
  <<-HEREDOC
    <executable name='kolibri_description'>
      <command>roslaunch --wait asl_voliro_kolibri description.launch world_name:=#{_worldName} name:=#{_name}</command>
    </executable>
    <executable name='kolibri_description_ros_ign_bridge'>
      <command>roslaunch --wait asl_voliro_kolibri vehicle_topics.launch world_name:=#{_worldName} name:=#{_name} uav:=1 laser_scan:=0 top_scan:=1 bottom_scan:=1 rgbd_cam:=1    </command>
  </executable>
  HEREDOC
end
