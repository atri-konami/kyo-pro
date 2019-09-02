q = gets.to_i

1.upto(q){
    s,t = gets.chomp.split

    if s.include?(t)
        puts "YES"
        next
    end

    p = String.new(s)

    t.each_char{|x|
        s.delete!(x)
    }

    s.each_char{|x|
        p.delete!(x)
    }

    if p.include?(t)
        puts "YES"
    else
        puts "NO"
    end
}
