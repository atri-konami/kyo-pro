s=gets.chomp

c=s.index("C")

unless c
    puts "No"
else
    f=s.index("F", c)

    if f && c < f
        puts "Yes"
    else
        puts "No"
    end
end

