function [] = lyricShuffle(str)
    %file = fopen(str,'r');
    newstr = str.split(".");
    s = newstr(1)+"_updated."+newstr(2);
    %file2 = fopen(s,'w');
    text = fileread(str);
    ns = regexprep(text, '\<you\>', 'me');
    ns = regexprep(ns, '\<the\>', 'these')
end