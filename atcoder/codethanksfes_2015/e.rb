q = gets.to_i

1.upto(q) {
    s,t = gets.chomp.split

    i=0
    chk = false
    d=[]
    mn = 100000

    if s.include?(t) 
        puts "YES"
        next
    end

    s.each_char{|x|
        if chk
            d << x
        end

        if x == t[i] || ( i > 1 && x != t[i-1])
            i += 1
            d.pop
            chk = true
            if i == t.size
                d.uniq!
                if d.size < mn
                    mn = d.size
                else
                    d.clear
                end
                chk = false
            end
        end
    }

    if i != t.size
        puts "NO"
    else
        chk = false
        d.uniq.each{|x|
            if t.include? x
                chk = true
                break
            end
        }

        puts chk ? "NO" : "YES"
    end
}

