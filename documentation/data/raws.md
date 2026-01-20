Similar to Dwarf Fortress (which certainly is the inspiration for many aspects of qxoxrogue), qxoxrogue uses "raws" to define most in-game assets in a reasonably easily moddable way.

# list of raws (base)
## Entity_Type raws (raw/entity)

## Item_Type raws (raw/item)
base_item : basic items wihtout an associated

## Material_Item_Type_Template raws (raw/item_template)
base_material_item : basic material item type templates, e.g. ingots, plates, nails, screws 
material_tool : item type templates for tools, e.g. anvils, hammers, graters

## Material raws (raw/material)
base_mats.txt : basic materials, e.g. water

## Structure raws (raw/structure)
TK - did I mention how structures literally aren't defined yet by anything in the code!!?! 

# object definition traits:
## in general :
ID : internal name for object
TAG : adds a tag

## Entity_Type :
TK

# Item_Type :
TK

# Material_Item_Type_Template :
TK

## Material :
SOLID_NAME : name in solid state
LIQUID_NAME : name in liquid state
GAS_NAME : name in gaseous state

COLOR : color to display

SOLID_DENSITY : density in solid state (g/m^3)
LIQUID_DENSITY : density in liquid state (g/m^3)
GAS_DENSITY : density in gas state (g/m^3)

MP : melting point
BP : boiling point

# list of tags
## Entity tags:
INCORPOREAL : does not render or have a physical location to greater precision than a tile.