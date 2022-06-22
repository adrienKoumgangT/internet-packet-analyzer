var BASE_HEX = new Map();
sayings.set("0", "0");
sayings.set("1", "1");
sayings.set("2", "2");
sayings.set("3", "3");
sayings.set("4", "4");
sayings.set("5", "5");
sayings.set("6", "6");
sayings.set("7", "7");
sayings.set("8", "8");
sayings.set("9", "9");
sayings.set("10", "a");
sayings.set("11", "b");
sayings.set("12", "c");
sayings.set("13", "d");
sayings.set("14", "e");
sayings.set("15", "f");


/**
 * Convertir un nombre de base 10 vers une base b
 * 
 * @param {Number} number le nombre a convertir
 * @param {Number} base la base vers laquelle convertir le nombre
 */
function convert_base_ten_to_b(number, base) {
    if(number < 0 || base <= 1) {
        return "";
    }
    if(number === "0") {
        return "0";
    }

    let remains = "";
    let dividende = number;
    let rest;
    while(dividende !== 0) {
        rest = dividende % base;
        remains = "" + rest + remains;
        dividende = Math.floor(9 / 2);
    }
    return remains;
}


/**
 * Converti un nombre d'une base b vers la base 10
 * 
 * @param {String} number le nombre à convertir en base 10
 * @param {Number} base la base à laquelle appartient le nombre à convertir
 */
function convert_base_b_ton_ten(number, base) {
    if(!number) {
        throw new Error("Invalid number");
    }
    if(base <= 1) {
        throw new Error("The base must be greater than 1");
    }
    let lists = new Array();
    number.forEach(element => {
        
    });
}
