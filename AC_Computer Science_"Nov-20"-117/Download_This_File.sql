drop schema if exists FE1;
create schema FE1;
use  FE1;

-- Start here if you are using Ash Connection to run the script
drop table if exists Supplies, Produce, ProduceType, Farmer;

-- Table Farmer
create table Farmer(
	FarmerID char(3),
    FarmerName varchar(40),
    FarmName varchar(40),
    FarmLocation varchar(40),
    primary key(FarmerID));

-- Insert data into Farmer Table
insert into Farmer values ('F20','Michael Schumacher', 'Blueberry Farms','Grafton, NSW');
insert into Farmer values ('F21','Lewis Hamilton ', 'Where Pigs Fly','Laguna, NSW');
insert into Farmer values ('F22','Daniel Ricciardo', 'Grow Greens Farms','Echuca, VIC');
insert into Farmer values ('F23','Alex Albon', 'Nico Farms','Renmark, SA');


-- Table ProduceType
create table ProduceType(
	ProdTypeID char(3),
    ProdTypeName varchar(20),
    primary key(ProdTypeID));

-- Insert data into ProduceType Table
insert into ProduceType values ('T10','Vegetables');
insert into ProduceType values ('T11','Fruits');
insert into ProduceType values ('T12','Greens');

-- Table Produce
create table Produce(
	ProduceID char(3),
	ProduceName varchar(20),
    ProdTypeID char(3),
    primary key(ProduceID),
    foreign key(ProdTypeID) references ProduceType(ProdTypeID));

-- Insert data into Produce Table
insert into Produce values ('P01','Apple','T11');
insert into Produce values ('P02','Orange','T11');
insert into Produce values ('P03','Zucchini','T10');
insert into Produce values ('P04','Spinach','T12');


-- Table Supplies
create table Supplies(
	ProduceID char(3),
	FarmerID char(3),
    Weight decimal(5,2),
    Metric varchar(10),
    PricePerWeight decimal(5,2),
    primary key(ProduceID,FarmerID),
    foreign key(ProduceID) references Produce(ProduceID),
    foreign key(FarmerID) references Farmer(FarmerID));

-- Insert data into Supplies Table
insert into Supplies values ('P01','F21', 2.5, 'Kilos',20.99);
insert into Supplies values ('P01','F22', 10.0, 'Kilos',99.99);
insert into Supplies values ('P04','F22', 300, 'grams',4.99);
insert into Supplies values ('P04','F23', 500, 'grams',6);
insert into Supplies values ('P02','F23', 1, 'Kilos',3);

-- Display values from tables
select *
from Farmer;

select *
from ProduceType;

select *
from Produce;

select *
from Supplies;
