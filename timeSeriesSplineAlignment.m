function timeSeriesSplineAlignment()
    close all;
    cellData = {}; 
    dataType = 'R_Torques.dat'; %R_CartPos.dat  R_Torques.dat R_Angles.dat 
    while length(cellData) ~= 5
        cellData = extract_file('SIM_HIRO_ONE_SA_SUCCESS', dataType,5) ;  
    end
    
    nbData = [];
    for i = 1: length(cellData)
        wrenchVec = cellData{i};
        % use the 2nd order equation to smooth the original signal
        temp = smoothWrenchFilter(wrenchVec);
        cellData{i} = temp';
        nbData = [nbData, size(cellData{i}, 2)]; % so as to find out the max length
    end
    
    for n=1:length(cellData)
        cellData{n} = spline(1:size(cellData{n},2), cellData{n}, linspace(1,size(cellData{n},2), max(nbData))); %Resampling        
    end
      
end