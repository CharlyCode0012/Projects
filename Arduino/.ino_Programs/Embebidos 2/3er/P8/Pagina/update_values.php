<?php

$vel = $_POST['Vel'];

$state = $_POST['State'];

$dir = $_POST['Dir'];

echo json_encode($vel.', '. $state.', '.$dir);
