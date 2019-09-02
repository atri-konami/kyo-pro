s=gets.chomp
r=[]

if s.include? '!'
    r.unshift("!")
    if(s.count("!") % 2 == 0)
        r.unshift("!")
    end
    idx = s.index("!",0)
    ss = s.slice(0,idx)
    if ss.size > 0 && ss.size % 2 == 1
        r.unshift("-")
    end

    puts r.join("")
else
    if s.size % 2 == 0
        puts
    else
        puts "-"
    end
end


