const express = require('express');
const userController = require('../controllers/userController');
const authController = require('../controllers/authController');

// ROUTER
const router = express.Router();

router.post('/signup', authController.signup);
router.post('/login', authController.login);

// this process is called mounting the router
// the following routes follow the REST APIs
router.route('/').get(userController.getAllUsers);
// .post(userController.createUser);
router
  .route('/:id')
  .get(userController.getUser)
  .patch(userController.updateUser)
  .delete(
    authController.protect,
    authController.restrictTo('admin'),
    userController.deleteUser
  );

module.exports = router;
