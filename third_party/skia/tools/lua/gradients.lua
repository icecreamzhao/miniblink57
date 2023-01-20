<<<<<<< HEAD
function sk_scrape_startcanvas(c, fileName) end
function sk_scrape_endcanvas(c, fileName) end

gradients = {}

i = 1
=======

function sk_scrape_startcanvas(c, fileName) end

function sk_scrape_endcanvas(c, fileName) end

count3 = 0
count3sym = 0
>>>>>>> miniblink49

function sk_scrape_accumulate(t)
    local p = t.paint
    if p then
        local s = p:getShader()
        if s then
            local g = s:asAGradient()
            if g then
<<<<<<< HEAD
                gradients[i] = {}
                gradients[i].colorCount        = g.colorCount
                gradients[i].type              = g.type
                gradients[i].tile              = g.tile
                gradients[i].isEvenlySpaced    = g.isEvenlySpaced
                gradients[i].containsHardStops = g.containsHardStops

                gradients[i].positions = {}
                for j = 1, g.colorCount, 1 do
                    gradients[i].positions[j] = g.positions[j]
                end

                i = i + 1
=======
                --io.write(g.type, " gradient with ", g.colorCount, " colors\n")
            
                if g.colorCount == 3 then
                   count3 = count3 + 1

                   if (g.midPos >= 0.499 and g.midPos <= 0.501) then
                      count3sym = count3sym + 1
                   end
                end    
>>>>>>> miniblink49
            end
        end
    end
end

<<<<<<< HEAD
function sk_scrape_summarize()
    for k, v in pairs(gradients) do
        local pos = ""
        for j = 1, v.colorCount , 1 do
            pos = pos .. v.positions[j]
            if j ~= v.colorCount then
                pos = pos .. ","
            end
        end

        io.write(string.format("%d %s %s %d %d %s\n",
                                v.colorCount,
                                v.type,
                                v.tile,
                                tonumber(v.isEvenlySpaced and 1 or 0),
                                tonumber(v.containsHardStops and 1 or 0),
                                pos))
    end
=======
function sk_scrape_summarize() 
         io.write("Number of 3 color gradients:  ", count3, "\n");
         io.write("Number of 3 color symmetric gradients:  ", count3sym, "\n");
>>>>>>> miniblink49
end

