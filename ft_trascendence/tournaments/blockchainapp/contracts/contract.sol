// SPDX-License-Identifier: MIT
pragma solidity ^0.8.10;

contract SimpleStorage {

  string first;
  string second;
  string third;
  string owner;
  uint myVariable;

  function set_Tournament(string memory _first, string memory _second, string memory _third,  string memory _owner, uint x) public {
    first = _first;
    second = _second;
    third = _third;
    owner = _owner;
    myVariable = x;
  }

  function get_Tournament() public view returns (string memory, string memory, string memory, string memory, uint) {
    return (first, second, third, owner, myVariable);
  }
}