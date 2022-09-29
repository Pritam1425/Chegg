function [arr,filename] = giveMeBreakfast(file)
    [text,remain] = strtok(fileread(file),"\n");
    text = lower(text)
    str = file.split(".");
    newname = str(1)+"_updated."+str(2)
    newans = 'What I need to make today is ';
    while 
    fid = fopen(newname,'w');
    
end