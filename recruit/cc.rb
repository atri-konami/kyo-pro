n = gets.chomp.to_i

def rep(n)
    if n <= 4
        return n
    end
    if n % 2 == 0
        return 2 + rep(n/2)
    else
        return 3 + rep(n/2)
    end
end

puts rep(n)
