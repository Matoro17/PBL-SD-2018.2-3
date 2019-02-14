library verilog;
use verilog.vl_types.all;
entity SM1 is
    generic(
        temp            : integer := 10000
    );
    port(
        reset           : in     vl_logic;
        clock           : in     vl_logic;
        dataa           : in     vl_logic_vector(31 downto 0);
        RXuart          : in     vl_logic;
        TXuart          : out    vl_logic;
        result          : out    vl_logic_vector(31 downto 0);
        done            : out    vl_logic;
        estado          : out    vl_logic
    );
    attribute mti_svvh_generic_type : integer;
    attribute mti_svvh_generic_type of temp : constant is 1;
end SM1;
