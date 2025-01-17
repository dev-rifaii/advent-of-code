io.input("d3-input.txt")

mul = function(x, y) return x * y end

local sum = 0
local file_contents = io.read("a")

local before_first_dont = file_contents:match("%mul%(%d+%,%d+%).-don't%(%)");
for k in before_first_dont:gmatch("%mul%(%d+%,%d+%)") do
    sum = sum + load('return ' .. k)()
end


for k in file_contents:gmatch("do%(%)(.-)don't%(%)") do
    for s in k:gmatch("%mul%(%d+%,%d+%)") do
        sum = sum + load('return ' .. s)()
    end
end

print(sum)
