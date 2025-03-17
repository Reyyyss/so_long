/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:42:51 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/03/17 17:50:22 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Flood fill function to check if player can collect all collectibles
void floodfill(int grid[ROWS][COLS], int x, int y, bool visited[ROWS][COLS]) {
    // If the position is out of bounds or already visited, stop
    if (!is_valid(x, y, grid) || visited[x][y]) {
        return;
    }

    // Mark this cell as visited
    visited[x][y] = true;

    // Explore 4 directions (down, up, right, left)
    floodfill(grid, x + 1, y, visited); // Down
    floodfill(grid, x - 1, y, visited); // Up
    floodfill(grid, x, y + 1, visited); // Right
    floodfill(grid, x, y - 1, visited); // Left