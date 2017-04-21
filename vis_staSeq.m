function vis_staSeq()
    for nSeq = 1:5
        run(nSeq);
    end
    figure;
    files = dir('../logs');
    for n = 1:length(files)
         if 0 < length(strfind(files(n).name,'stateSeq'))
             stateSeq = load(files(n).name);
             plot(stateSeq.stateSeq.z);
             hold on;
         end
    end
end