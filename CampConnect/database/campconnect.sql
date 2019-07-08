-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 28, 2018 at 09:10 AM
-- Server version: 10.1.35-MariaDB
-- PHP Version: 7.2.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `campconnect`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `ok` (IN `productName` VARCHAR(255), IN `type` VARCHAR(255), IN `today` VARCHAR(255), IN `expiry` VARCHAR(255), IN `owner_email` VARCHAR(255))  NO SQL
BEGIN 
INSERT INTO advertisement(item_name,item_type,date_of_init,date_of_exp,owner_id) VALUES(productName,type,today,expiry,owner_email); 
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `advertisement`
--

CREATE TABLE `advertisement` (
  `advt_id` int(100) NOT NULL,
  `item_name` varchar(255) DEFAULT NULL,
  `item_type` varchar(255) DEFAULT NULL,
  `date_of_init` varchar(255) DEFAULT NULL,
  `date_of_exp` varchar(255) DEFAULT NULL,
  `owner_id` varchar(255) DEFAULT NULL,
  `buyer_id` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `advertisement`
--

INSERT INTO `advertisement` (`advt_id`, `item_name`, `item_type`, `date_of_init`, `date_of_exp`, `owner_id`, `buyer_id`) VALUES
(1, 'Hp Probook 4420', 'Laptop', '2018-10-07', '2018-10-17', 'kenil@gmail.com', 'vinod@gmail.com'),
(2, 'Dell Vostro', 'Laptop', '2018-10-07', '2018-10-17', 'praj12121998@gmail.com', 'kenil@gmail.com'),
(3, 'Lenovo think pad', 'Laptop', '2018-10-07', '2018-10-17', 'praj12121998@gmail.com', 'surabh@gmail.com'),
(4, 'IPHONE TEN !! 256Gb Fresh Condition So Dont Miss', 'Mobile', '2018-10-07', '2018-10-17', 'praj12121998@gmail.com', NULL),
(5, 'J7 prime 32gb new condition,negotiable', 'Mobile', '2018-10-07', '2018-10-17', 'surabh@gmail.com', 'praj12121998@gmail.com'),
(6, ' Redmi 4 3gb ram, 32gb internal', 'Mobile', '2018-10-07', '2018-10-17', 'surabh@gmail.com', NULL),
(7, 'System Software  3rd', 'Book', '2018-10-07', '2018-10-17', 'surabh@gmail.com', NULL),
(8, 'Computers as components ', 'Book', '2018-10-07', '2018-10-17', 'surabh@gmail.com', 'praj12121998@gmail.com'),
(9, 'Operating system concept-8th edition', 'Book', '2018-10-07', '2018-10-17', 'vinod@gmail.com', NULL),
(10, 'HP 6510 ', 'Laptop', '2018-10-07', '2018-10-17', 'vinod@gmail.com', NULL),
(11, 'Dell Inspiron', 'Laptop', '2018-10-07', '2018-10-17', 'vinod@gmail.com', NULL),
(12, 'toshiba satellite', 'Laptop', '2018-11-19', '2018-11-29', 'kenil@gmail.com', 'vinod@gmail.com'),
(13, 'dbms', 'Book', '2018-11-20', '2018-11-30', 'kenil@gmail.com', 'vinod@gmail.com'),
(14, 'redmi note 5 pro', 'Mobile', '2018-11-24', '2018-12-04', 'kenil@gmail.com', NULL),
(15, 'kjhhjuv', 'Mobile', '2018-11-28', '2018-12-08', 'aksh@gmail.com', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `author`
--

CREATE TABLE `author` (
  `product_id` int(100) DEFAULT NULL,
  `author_name` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `author`
--

INSERT INTO `author` (`product_id`, `author_name`) VALUES
(7, 'Leland l beck'),
(7, ' D Manjula'),
(8, 'Wayne Wolf'),
(9, 'A silberschatz'),
(9, 'P Galvin'),
(9, 'Gagne'),
(13, 'asddd'),
(15, 'as'),
(15, 'as');

-- --------------------------------------------------------

--
-- Table structure for table `book`
--

CREATE TABLE `book` (
  `product_id` int(100) NOT NULL,
  `name_of_book` varchar(255) DEFAULT NULL,
  `condition_book` varchar(255) DEFAULT NULL,
  `ad_description` varchar(255) DEFAULT NULL,
  `expected_price` varchar(255) DEFAULT NULL,
  `image_path` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `book`
--

INSERT INTO `book` (`product_id`, `name_of_book`, `condition_book`, `ad_description`, `expected_price`, `image_path`) VALUES
(7, 'System Software  3rd', ' Very Good', 'Important book for Software development', '199', NULL),
(8, 'Computers as components ', 'Good', '2nd Edition ', '299', NULL),
(9, 'Operating system concept-8th edition', 'Almost New', 'Useful for Computer Science students', '299', NULL),
(13, 'dbms', 'new', 'czczfsdfs', '123', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `laptop`
--

CREATE TABLE `laptop` (
  `product_id` int(100) NOT NULL,
  `manufacturer` varchar(255) DEFAULT NULL,
  `model_name` varchar(255) DEFAULT NULL,
  `year_of_purchase` varchar(255) DEFAULT NULL,
  `battery_status` varchar(255) DEFAULT NULL,
  `ad_description` varchar(255) DEFAULT NULL,
  `expected_price` varchar(255) DEFAULT NULL,
  `image_path` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `laptop`
--

INSERT INTO `laptop` (`product_id`, `manufacturer`, `model_name`, `year_of_purchase`, `battery_status`, `ad_description`, `expected_price`, `image_path`) VALUES
(1, 'HP', 'HPS12/9Q2378256iA2', '2017', ' 3 hours battery', 'Hp Probook 4420 i5 / 4 GB / 320 GB / dvd writer/ WiFi /webcam /14.0/ good working condition.', '10500', NULL),
(2, 'DELL', 'DV1290', '2015', '2 hours battery', '4 GB ram/ 500 GB hard disk/ 15.6 led screen good working condition', '9999', NULL),
(3, 'Lenovo', 'LT7462/i2329', '2010', '2 hours battery backup', 'Lenovo think pad. i3 2nd / 4 gb / 320 gb / 14.0 screen wifi / webcam / good working condition', '9500', NULL),
(10, 'HP', 'HP9778675', '2012', ' 3 hours battery', 'Intel CORE i5 With 1GB Graphic Card ', '11000', NULL),
(11, 'DELL', '5559 ', '2017', '4 hours battery', 'i3 6100/4gb/1tb/2gb/black ', '31000', NULL),
(12, 'toshiba', '6789', '2015', '3 hrs', 'nothing', '1200000', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `messages`
--

CREATE TABLE `messages` (
  `msg_id` int(100) NOT NULL,
  `sender_id` varchar(255) DEFAULT NULL,
  `receiver_id` varchar(255) DEFAULT NULL,
  `message` varchar(255) DEFAULT NULL,
  `msg_date` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `messages`
--

INSERT INTO `messages` (`msg_id`, `sender_id`, `receiver_id`, `message`, `msg_date`) VALUES
(6, 'aksh@gmail.com', 'kenil@gmail.com', 'ffawefeafgtaegraegeahgrthrshsrhsgbd', '2018-11-28 13:26:00');

--
-- Triggers `messages`
--
DELIMITER $$
CREATE TRIGGER `trig` BEFORE INSERT ON `messages` FOR EACH ROW BEGIN
	SET NEW.msg_date = NOW();
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `mobile`
--

CREATE TABLE `mobile` (
  `product_id` int(100) NOT NULL,
  `manufacturer` varchar(255) DEFAULT NULL,
  `model_name` varchar(255) DEFAULT NULL,
  `year_of_purchase` varchar(255) DEFAULT NULL,
  `ad_description` varchar(255) DEFAULT NULL,
  `expected_price` varchar(255) DEFAULT NULL,
  `image_path` blob
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `mobile`
--

INSERT INTO `mobile` (`product_id`, `manufacturer`, `model_name`, `year_of_purchase`, `ad_description`, `expected_price`, `image_path`) VALUES
(4, 'Apple', 'IP9248', '2018 (recently)', 'Brand New ', '59999', NULL),
(5, 'Samsung', 'SJ7070', '2018 (recently)', 'bill box accessories available', '7900', NULL),
(6, 'MI', 'MIR3872', '2017', 'Good Condition 3gb ram, 32gb internal memory 12mp rear camera 5mp front camera 4000mAh Battery', '7000', NULL),
(14, 'xiaomi', '6783', '2014', 'jsdvdvsiiisisuihjujn', '12000', NULL),
(15, 'rststs', 'yyuyuyufyyuyufyuf', '2014', 'vuvufyvucfucu', '656646', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `Nitc_email_id` varchar(255) NOT NULL,
  `User_name` varchar(255) DEFAULT NULL,
  `Mobile_no` varchar(255) DEFAULT NULL,
  `User_type` varchar(255) DEFAULT NULL,
  `User_password` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`Nitc_email_id`, `User_name`, `Mobile_no`, `User_type`, `User_password`) VALUES
('aksh@gmail.com', 'aksh', '123654789', 'Faculty', '123'),
('kenil@gmail.com', 'kenil', '24466366', 'Faculty', '1234'),
('praj12121998@gmail.com', 'Prajwal', '9757318791', 'Student', '1234'),
('surabh@gmail.com', 'Saurabh Marpallikar', '8403361093', 'Student', '1234'),
('vinod@gmail.com', 'vinod', '434356446', 'Student', '1234');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `advertisement`
--
ALTER TABLE `advertisement`
  ADD PRIMARY KEY (`advt_id`),
  ADD KEY `owner_id` (`owner_id`),
  ADD KEY `buyer_id` (`buyer_id`);

--
-- Indexes for table `book`
--
ALTER TABLE `book`
  ADD PRIMARY KEY (`product_id`);

--
-- Indexes for table `laptop`
--
ALTER TABLE `laptop`
  ADD PRIMARY KEY (`product_id`);

--
-- Indexes for table `messages`
--
ALTER TABLE `messages`
  ADD PRIMARY KEY (`msg_id`),
  ADD KEY `sender_id` (`sender_id`),
  ADD KEY `receiver_id` (`receiver_id`);

--
-- Indexes for table `mobile`
--
ALTER TABLE `mobile`
  ADD PRIMARY KEY (`product_id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`Nitc_email_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `advertisement`
--
ALTER TABLE `advertisement`
  MODIFY `advt_id` int(100) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `messages`
--
ALTER TABLE `messages`
  MODIFY `msg_id` int(100) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `advertisement`
--
ALTER TABLE `advertisement`
  ADD CONSTRAINT `Advertisement_ibfk_1` FOREIGN KEY (`owner_id`) REFERENCES `users` (`Nitc_email_id`),
  ADD CONSTRAINT `Advertisement_ibfk_2` FOREIGN KEY (`buyer_id`) REFERENCES `users` (`Nitc_email_id`);

--
-- Constraints for table `book`
--
ALTER TABLE `book`
  ADD CONSTRAINT `book_ibfk_1` FOREIGN KEY (`product_id`) REFERENCES `advertisement` (`advt_id`);

--
-- Constraints for table `laptop`
--
ALTER TABLE `laptop`
  ADD CONSTRAINT `laptop_ibfk_1` FOREIGN KEY (`product_id`) REFERENCES `advertisement` (`advt_id`);

--
-- Constraints for table `messages`
--
ALTER TABLE `messages`
  ADD CONSTRAINT `messages_ibfk_1` FOREIGN KEY (`sender_id`) REFERENCES `users` (`Nitc_email_id`),
  ADD CONSTRAINT `messages_ibfk_2` FOREIGN KEY (`receiver_id`) REFERENCES `users` (`Nitc_email_id`);

--
-- Constraints for table `mobile`
--
ALTER TABLE `mobile`
  ADD CONSTRAINT `mobile_ibfk_1` FOREIGN KEY (`product_id`) REFERENCES `advertisement` (`advt_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
