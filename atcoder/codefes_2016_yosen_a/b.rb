n=gets.to_i
a=gets.chomp.split.map(&:to_i)
s=0
a.each_with_index{|x, i|
    if a[x-1] == i+1
        s+=1
    end
}
puts s/2
