n,t=gets.chomp.split.map(&:to_i)
a=[];b=[];

as=0
bs=0
for i in 0...n
    s,ss=gets.chomp.split.map(&:to_i)
    a<<s
    b<<ss
    as+=s
    bs+=ss
end

if bs > t
    puts -1
    exit
elsif as <= t
    puts 0
    exit
end

dif=[]

for i in 0...n
    dif<<a[i]-b[i]
end

dif = dif.sort.reverse

res=0

for i in 0...n
    as-=dif[i]
    res+=1
    if as <= t
        puts res
        exit
    end
end

puts -1



