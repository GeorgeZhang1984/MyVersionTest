SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

DROP TABLE IF EXISTS `file_block` ;

CREATE TABLE IF NOT EXISTS `file_block` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `block_data` BLOB NOT NULL,
  `block_hash` VARCHAR(45) NOT NULL,
  `create_date` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `fileversion`.`user`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `user` ;

CREATE TABLE IF NOT EXISTS `user` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `username` VARCHAR(45) NOT NULL,
  `password` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `fileversion`.`file_arc`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `file_arc` ;

CREATE TABLE IF NOT EXISTS `file_arc` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `file_name` VARCHAR(45) NOT NULL,
  `user_id` INT NOT NULL,
  `curr_version` VARCHAR(45) NOT NULL,
  `curr_hash` VARCHAR(45) NOT NULL,
  `file_length` INT NOT NULL,
  `create_date` DATETIME NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `fk_user_id`
    FOREIGN KEY (`user_id`)
    REFERENCES `user` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `fileversion`.`file_version`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `file_version` ;

CREATE TABLE IF NOT EXISTS `file_version` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `version_num` INT NOT NULL,
  `file_arc_id` INT NOT NULL,
  `block_id` INT NOT NULL,
  `file_length` INT NOT NULL,
  `create_date` DATETIME NOT NULL,
  `file_hash` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `fk_block_id`
    FOREIGN KEY (`block_id`)
    REFERENCES `file_block` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_file_arc_id`
    FOREIGN KEY (`file_arc_id`)
    REFERENCES `file_arc` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

alter table file_version add line_num int after file_hash;

-- -----------------------------------------------------
-- Table `fileversion`.`comments`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `comments` ;

CREATE TABLE IF NOT EXISTS `comments` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `file_version_id` INT NULL,
  `comments` VARCHAR(45) NULL,
  `create_date` DATETIME NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `fk_version_id`
    FOREIGN KEY (`file_version_id`)
    REFERENCES `file_version` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;
-- -----------------------------------------------------
-- Placeholder table for view `iphealthproject`.`view1`
-- -----------------------------------------------------

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

ALTER TABLE `user` ADD UNIQUE INDEX `User_Name_UNIQUE` (`username`);
ALTER TABLE `file_arc` ADD UNIQUE INDEX `File_name_UNIQUE` (`file_name`);


insert into `user` (`username`,`password`) values ('hz740' , '123456');
commit;
