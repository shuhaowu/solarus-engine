local map = ...
local game = map:get_game()

function map:on_opening_transition_finished()

  local sprite = robyne:get_sprite()
  local movement = sol.movement.create("straight")
  movement:set_angle(0)
  movement:set_speed(96)
  movement:start(robyne)
  assert(not movement:get_ignore_suspend())

  sol.timer.start(map, 500, function()
    game:set_paused(true)
    sol.timer.start(sol.main, 500, function()
      assert(movement:is_suspended())
      assert(not sprite:get_ignore_suspend())
      game:set_paused(false)
      sol.timer.start(sol.main, 100, function()
        assert(not movement:is_suspended())

        movement:set_ignore_suspend(true)
        sol.timer.start(map, 500, function()
          game:set_paused(true)
          sol.timer.start(sol.main, 500, function()
            assert(not movement:is_suspended())
            assert(not sprite:get_ignore_suspend())
            game:set_paused(false)
            sol.timer.start(sol.main, 100, function()
              assert(not movement:is_suspended())
              sol.main.exit()
            end)
          end)
        end)
      end)
    end)
  end)
end