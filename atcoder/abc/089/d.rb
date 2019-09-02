dd = [0, 1, -1]
h,w = gets.chomp.split.map(&:to_i)
s1 = []
s2 = []

(0...h).each{
    str = gets.chomp
    str2 = Marshal.load(Marshal.dump(str))
    s1 << str
    s2 << str2
}

(0...h).each{|hh|
    (0...w).each{|ww|
        if s1[hh][ww] == '.'
            dd.each{|d1|
                dd.each{|d2|
                next if d1 == 0 && d2 == 0
                s2[hh+d1][ww+d2] = '.' if (0...h).include?(hh+d1) && (0...w).include?(ww+d2)
                }
            }
        end
    }
}

(0...h).each{|hh|
    (0...w).each{|ww|
        if s1[hh][ww] == '.' && s2[hh][ww] == '#'
            puts 'impossible'
            exit
        end
        if s1[hh][ww] == '#' && s2[hh][ww] == '.'
            flag = false
            dd.each{|d1| dd.each{|d2|
                next if d1 == 0 && d2 == 0
                if (0...h).include?(hh+d1) && (0...w).include?(ww+d2)
                    flag = flag || s2[hh+d1][ww+d2] == '#'
                end
            }}
            if !flag
                puts 'impossible'
                exit
            end
        end
    }
}

puts 'possible'
s2.each{|str|
    puts str
}

