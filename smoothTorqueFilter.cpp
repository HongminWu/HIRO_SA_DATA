  /***************************************************************************** Filtering ************************************************************************************/
    // Create a vector or 6D Eigen vectors
    Eigen::VectorXd temp = Eigen::VectorXd::Zero(6);    

    if(wrenchFilteringFlag)
      {
        // If this is the first loop we need to insert two rows with equal values as the current iteration for both wrenchVec and wrenchVecF
        if(initialFiltering)
          {
            for(int i=0; i<2; i++)
              {
                // Input wrench at the end of the vector
                wrenchVec.push_back(cur_data_);               

                // Filtered wrench at the end of the vector
                wrenchVecF.push_back(cur_data_);
              }
            // Change Flag
            initialFiltering=false;
          }

        // Copy new data to wrenchVec at the end of the vector
        wrenchVec.push_back(cur_data_);
        
        // Assuming a vector of size(3:0,1,2) Element [2] is the current one (sitting at the back), element t-1 is [1], sitting in the middle, and element t-2 is[0]. 
        // The indeces are opposite to what you think it should be. 
        for(int i=0; i<6; i++)
          temp(i) = 0.018299*wrenchVec[2](i) + 0.036598*wrenchVec[1](i) + 0.018299*wrenchVec[0](i) + 1.58255*wrenchVecF[1](i) - 0.65574*wrenchVecF[0](i);

        // Add new filtered result
        wrenchVecF.push_back(temp);

        // Pop last value from these two structures to keep the size of the vector to 3 throughout
        wrenchVec.pop_front();
        wrenchVecF.pop_front();
      }

    // Set filterd value to private member
    for(int i=0; i<6; i++)
      cur_data_f_(i) = wrenchVecF[0](i);

    baxter_core_msgs::EndpointState fw;
    // Time Stamp
    fw.header.stamp = ros::Time::now();

    // Wrench
    fw.wrench.force.x  = cur_data_f_(0); 
    fw.wrench.force.y  = cur_data_f_(1); 
    fw.wrench.force.z  = cur_data_f_(2); 
    fw.wrench.torque.x = cur_data_f_(3); 
    fw.wrench.torque.y = cur_data_f_(4); 
    fw.wrench.torque.z = cur_data_f_(5); 

    // Republish. Leading to system crash..
    if(filtered_wrench_pub_flag)
      {
        filtered_wrench_pub_.publish(fw);
        // ROS_INFO_STREAM("Publishing the filtered wrench: " << fw.wrench << std::endl);
      }

    //}
 // }
